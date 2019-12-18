public class WarnsDorffKnight{
  private int row_coordinate;
  private int column_coordinate;


  public WarnsDorffKnight(int x_position, int y_position){
    row_coordinate = x_position;
    column_coordinate = y_position;
  }

  public int getRowCoordinate(){
    return row_coordinate;
  }

  public int getColumnCoordinate(){
    return column_coordinate;
  }

  public void moveKnight(int row_move, int column_move){
    row_coordinate = row_move;
    column_coordinate = column_move;
  }

  public boolean checkLimit(int row, int column, int[][] checkChessBoard, int boardSize)
  {
    if ((!((row >= boardSize) || (row < 0) || (column >= boardSize) || (column < 0))) && (checkChessBoard[row][column] == 0))
    {
      return true;
    }
    else{
      return false;
    }
  }

  public int numberOfPossibleMoves(int row, int column, int boardSize, int[][] board)
  {
    int possibleMoves = 0;

    //8 possible ways knight can move from a index
    //first way (1, 2)
    int temp_row_coordinate = row;
    int temp_column_coordinate = column;
    temp_row_coordinate += 1;
    temp_column_coordinate +=2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }

    //second way (1, -2)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += 1;
    temp_column_coordinate += -2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }

    //third way (2, 1)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += 2;
    temp_column_coordinate += 1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    //fourth way (2, -1)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += 2;
    temp_column_coordinate += -1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    //fifth way (-1, 2)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += -1;
    temp_column_coordinate += 2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    //sixth way (-1, -2)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += -1;
    temp_column_coordinate += -2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    //seventh way (-2, 1)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += -2;
    temp_column_coordinate += 1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    //eigth way (-2, -1)
    temp_row_coordinate = row;
    temp_column_coordinate = column;
    temp_row_coordinate += -2;
    temp_column_coordinate += -1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      possibleMoves++;
    }


    return possibleMoves;
  }


  public Coordinates getLowestMoveCoordinates(int boardSize, int[][] board){
    int temp_row_coordinate = row_coordinate;
    int temp_column_coordinate = column_coordinate;
    int lowestMove = 0;
    int moveChoice = 0;
    int moveCount = 0;

    //first way (1, 2)
    temp_row_coordinate += 1;
    temp_column_coordinate +=2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      lowestMove = moveCount;
      moveChoice = 1;
    }

    //second way (1, -2)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += 1;
    temp_column_coordinate += -2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 2;
      }
    }

    //third way (2, 1)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += 2;
    temp_column_coordinate += 1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 3;
      }
    }

    //fourth way (2, -1)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += 2;
    temp_column_coordinate += -1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 4;
      }
    }

    //fifth way (-1, 2)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += -1;
    temp_column_coordinate += 2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 5;
      }
    }

    //sixth way (-1, -2)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += -1;
    temp_column_coordinate += -2;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 6;
      }
    }

    //seventh way (-2, 1)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += -2;
    temp_column_coordinate += 1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 7;
      }
    }

    //eigth way (-2, -1)
    temp_row_coordinate = row_coordinate;
    temp_column_coordinate = column_coordinate;
    temp_row_coordinate += -2;
    temp_column_coordinate += -1;
    if (checkLimit(temp_row_coordinate, temp_column_coordinate, board, boardSize))
    {
      moveCount = numberOfPossibleMoves(temp_row_coordinate, temp_column_coordinate, boardSize, board);
      if ((moveCount < lowestMove) || (moveChoice == 0))
      {
        lowestMove = moveCount;
        moveChoice = 8;
      }
    }


    Coordinates coordinate;
    switch(moveChoice)
    {
      case 1:
        coordinate = new Coordinates(row_coordinate + 1, column_coordinate + 2);
        return coordinate;
      case 2:
        coordinate = new Coordinates(row_coordinate + 1, column_coordinate - 2);
        return coordinate;
      case 3:
        coordinate = new Coordinates(row_coordinate + 2, column_coordinate + 1);
        return coordinate;
      case 4:
        coordinate = new Coordinates(row_coordinate + 2, column_coordinate - 1);
        return coordinate;
      case 5:
        coordinate = new Coordinates(row_coordinate - 1, column_coordinate + 2);
        return coordinate;
      case 6:
        coordinate = new Coordinates(row_coordinate - 1, column_coordinate - 2);
        return coordinate;
      case 7:
        coordinate = new Coordinates(row_coordinate - 2, column_coordinate + 1);
        return coordinate;
      case 8:

        coordinate = new Coordinates(row_coordinate - 2, column_coordinate - 1);
        return coordinate;
      default:
        coordinate = new Coordinates(0,0);
        return coordinate;
    }

  }











}
