public class WarnsDorffBoard{
  private int[][] chessboard;
  private int size;
  private int turnNumber;


  public WarnsDorffBoard(int size, WarnsDorffKnight knight)
  {
    this.size = size;
    turnNumber = 1;
    chessboard = new int[size][size];
    chessboard[knight.getRowCoordinate()][knight.getColumnCoordinate()] = turnNumber++;
  }

  public void printChessBoard()
  {
    for (int i = 0; i < size; ++i)
    {
      for (int j = 0; j < size; ++j)
      {
        System.out.print(chessboard[i][j]);
        System.out.print("\t");
      }
      System.out.println();
    }
  }

  public int[][] getChessBoard()
  {
    return chessboard;
  }

  public void updateBoard(WarnsDorffKnight knight)
  {
    chessboard[knight.getRowCoordinate()][knight.getColumnCoordinate()] = turnNumber++;
  }

  public boolean isBoardFull()
  {
    for (int i = 0; i < size; ++i)
    {
      for (int j = 0; j < size; ++j)
      {
        if (chessboard[i][j] == 0)
        {
          return false;
        }
      }
    }
    return true;
  }

}
