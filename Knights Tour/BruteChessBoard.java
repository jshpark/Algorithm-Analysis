public class BruteChessBoard{

    private int[][] chessBoard;
    private int size;
    private int turnNumber;

    public BruteChessBoard(int size, BruteKnight knight)
    {
      turnNumber = 1;
      this.size = size;
      chessBoard = new int[size][size];
      chessBoard[knight.getRowCoordinate()][knight.getColumnCoordinate()] = turnNumber++;
    }



    public void printChessBoard()
    {
      for (int i = 0; i < size; ++i)
      {
        for (int j = 0; j < size; ++j)
        {
          System.out.print(chessBoard[i][j]);
          System.out.print("\t");
        }
        System.out.println();
      }
    }

    public int[][] getChessBoard()
    {
      return chessBoard;
    }

    public void updateBoard(BruteKnight knight)
    {
      chessBoard[knight.getRowCoordinate()][knight.getColumnCoordinate()] = turnNumber++;
    }

    public boolean isBoardFull()
    {
      for (int i = 0; i < size; ++i)
      {
        for (int j = 0; j < size; ++j)
        {
          if (chessBoard[i][j] == 0)
          {
            return false;
          }
        }
      }
      return true;
    }

    public void resetBoard(int old_row, int old_column)
    {
      for (int i = 0; i < size; ++i)
      {
        for (int j = 0; j < size; ++j)
        {
          chessBoard[i][j] = 0;
        }
      }
      turnNumber = 0;
      chessBoard[old_row][old_column] = turnNumber++;
    }




}
