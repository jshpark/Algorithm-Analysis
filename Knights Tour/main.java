/*
John Park
002298927
sanpark@chapman.edu
cpsc 408
Knight's Tour
*/

import java.util.Scanner;


public class main
{
  public static void main(String[] args)
  {
    Scanner keyboard = new Scanner(System.in);
    int size = Integer.parseInt(args[0]);
    int row_position= Integer.parseInt(args[1]);
    int column_position = Integer.parseInt(args[2]);
    String styleChoice = args[3];

    if (styleChoice.equals("--bf"))
    {
      //BRUTE FORCE METHOD
      BruteKnight bruteKnight = new BruteKnight(row_position, column_position, size);
      BruteChessBoard bruteBoard = new BruteChessBoard(size, bruteKnight);
      bruteBoard.printChessBoard();
      System.out.println();
      System.out.println();
      System.out.println();

      while (true)
      {
        bruteKnight.moveKnight(bruteBoard, row_position, column_position);
        bruteBoard.updateBoard(bruteKnight);
        if (bruteBoard.isBoardFull())
        {
          break;
        }
      }
      bruteBoard.printChessBoard();
    }

    if (styleChoice.equals("--h"))
    {
      //WARNSDORFF'S METHOD
      WarnsDorffKnight warnsKnight = new WarnsDorffKnight(row_position, column_position);
      WarnsDorffBoard warnsBoard = new WarnsDorffBoard(size, warnsKnight);
      warnsBoard.printChessBoard();

      System.out.println();
      System.out.println();
      System.out.println();

      while(true)
      {
        Coordinates coordinate = warnsKnight.getLowestMoveCoordinates(size, warnsBoard.getChessBoard());
        int row = coordinate.getRow();
        int column = coordinate.getColumn();
        warnsKnight.moveKnight(row, column);
        warnsBoard.updateBoard(warnsKnight);
        if (warnsBoard.isBoardFull())
        {
          break;
        }
      }
      warnsBoard.printChessBoard();
    }
  }
}
