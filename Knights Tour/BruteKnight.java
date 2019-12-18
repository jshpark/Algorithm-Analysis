import java.util.Random;
import java.util.LinkedList;
import java.util.Queue;

public class BruteKnight{
  private int row_coordinate;
  private int column_coordinate;
  private int boardSize;
  private BruteChessBoard checkBoard;
  private int[][] tempBoard;
  private Queue<Coordinates> history;

  public BruteKnight(int row_coordinate, int column_coordinate, int boardSize)
  {
    this.row_coordinate = row_coordinate;
    this.column_coordinate = column_coordinate;
    this.boardSize = boardSize;
    Coordinates coordinate = new Coordinates(this.row_coordinate, this.column_coordinate);
    history = new LinkedList<>();
    history.add(coordinate);
  }

  public void resetKnight(int row_coordinate, int column_coordinate)
  {
    this.row_coordinate = row_coordinate;
    this.column_coordinate = column_coordinate;
  }

  public void moveKnight(BruteChessBoard checkBoard, int old_row, int old_column)
  {
    //knights can only move in an L shape
    Random random = new Random();
    int checkTurns = 0;
    while (true)
    {
      int temp_row_coordinate = row_coordinate;
      int temp_column_coordinate = column_coordinate;

      int direction = random.nextInt(4) + 1;   //1=north west , 2=north east , 3=south west , 4=south east
      int style = random.nextInt(2) + 1;      //1=short then long, 2=long then short
      switch (direction)
      {
        case 1: //if north west
          switch (style)
          {
            case 1: //if short then long
              temp_row_coordinate -= 2;
              temp_column_coordinate -= 1;
              break;
            case 2:
              temp_row_coordinate -= 1;
              temp_column_coordinate -= 2;
              break;
          }
          break;
        case 2: //if north east
          switch (style)
          {
            case 1:
              temp_row_coordinate -= 2;
              temp_column_coordinate += 1;
              break;
            case 2:
              temp_row_coordinate -= 1;
              temp_column_coordinate += 2;
              break;
          }
          break;
        case 3: //if south west
          switch (style)
          {
            case 1:
              temp_row_coordinate += 1;
              temp_column_coordinate -=2;
              break;
            case 2:
              temp_row_coordinate += 2;
              temp_column_coordinate -=1;
              break;
          }
          break;
        case 4: //if south east
          switch (style)
          {
            case 1:
              temp_row_coordinate += 1;
              temp_column_coordinate +=2 ;
              break;
            case 2:
              temp_row_coordinate +=2 ;
              temp_column_coordinate +=1 ;
              break;
          }
          break;
      }
      if ((temp_row_coordinate >= boardSize) || (temp_row_coordinate < 0) || (temp_column_coordinate >= boardSize) || (temp_column_coordinate < 0))
      {
        continue;
      }
      else
      {
        if (checkTurns == 4)
        {
          //do not reset board, but backtrack using the queue
          checkBoard.resetBoard(old_row, old_column);
          row_coordinate = old_row;
          column_coordinate = old_column;
          break;
        }
        tempBoard = checkBoard.getChessBoard();
        if (tempBoard[temp_row_coordinate][temp_column_coordinate] != 0)
        {
          checkTurns++;
          continue;
        }
        row_coordinate = temp_row_coordinate;
        column_coordinate = temp_column_coordinate;
        Coordinates coordinate = new Coordinates(row_coordinate, column_coordinate);
        history.add(coordinate);
        break;
      }
    }
  }

  public String getKnightPosition()
  {
    return "(" + Integer.toString(row_coordinate) + ", " + Integer.toString(column_coordinate) + ")";
  }

  public int getRowCoordinate()
  {
    return row_coordinate;
  }

  public int getColumnCoordinate()
  {
    return column_coordinate;
  }

  public boolean checkLastCoordinate(BruteChessBoard checkBoard)
  {
    boolean check = true;
    int checkNumber = 0;
    tempBoard = checkBoard.getChessBoard();
    for (int i = 0; i < boardSize; ++i)
    {
      for (int j = 0; j < boardSize; ++j)
      {
        if (tempBoard[i][j] == 0)
        {
          checkNumber++;
        }
        if (checkNumber > 2)
        {
          return false;
        }
      }
    }
    return true;
  }









}
