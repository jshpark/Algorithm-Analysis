import java.lang.Math;
import java.util.Scanner;

public class EggDrop{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    EggDrop simulation = new EggDrop();
    System.out.print("How many eggs are there?: ");
    int eggs = scanner.nextInt();
    scanner.nextLine();
    System.out.print("How many floors are there?: ");
    int floors = scanner.nextInt();

    // System.out.println(simulation.DPEggDrop(eggs,floors));
    System.out.println("The minimum number of trials is " + simulation.DPEggDrop(eggs, floors)); 
  }

  //DYNAMIC PROGRAMMING METHOD
  public int DPEggDrop(int egg, int floor){
    int eggRecord[][] = new int[egg + 1][floor + 1];

    for (int i = 0; i <= floor; ++i){
      eggRecord[0][i] = 0;
      eggRecord[1][i] = i;
      // eggRecord[0][i] = i+1;
    }

    for (int i = 0; i <= egg; ++i){
      eggRecord[i][0] = 0;
      // eggRecord[i][0] = 1;
    }

    // eggRecord[0][1] = 0;

    //filled in top two rows and left two columns THIS IS GIVEN BC 0 FLOOR HAS 0 TRIES AND 1 EGG HAS J TRIES FOR J FLOORS
    //1 FLOOR IS ALWAYS 1 TRY EXCEPT FOR 0 EGGS

    //now we need to start from [2][2] and keep filling in data
    for (int i = 2; i <= egg; ++i){ //iterate downward
      for (int j = 2; j <= floor; ++j){ //iterate across {
        eggRecord[i][j] = Integer.MAX_VALUE;
        for (int k = 1; k <= j; ++k){ //this for loop is to test "each" floor and get the lowest value and make a record of it
          int record = Math.max(eggRecord[i-1][k-1], eggRecord[i][j-k]) + 1;
          if (eggRecord[i][j] > record){
            eggRecord[i][j] = record;
          }
        }
      }
    }
    return eggRecord[egg][floor];
  }
}


/*
  //RECURSIVE METHOD
  static int getDrops(int eggs, int floors){
    if (floors==0){
      return 0;
    }
    if (floors==1){
      return 1;
    }
    if (eggs==1){
      return floors;
    }

    int minDrops = Integer.MAX_VALUE;
    int intermediate;

    for (int i = 0; i <= floors; ++i){
      intermediate=max(getDrops(eggs-1 , i-1), getDrops(eggs , floors-i));
      minDrops = min(intermediate, minDrops);
    }
    return minDrops+1;
  }
}
*/
