public class Coordinates
{
  private int row_coordinate;
  private int column_coordinate;

  public Coordinates()
  {
    row_coordinate = 0;
    column_coordinate = 0;
  }

  public Coordinates(int x, int y)
  {
    row_coordinate = x;
    column_coordinate = y;
  }

  public int getRow()
  {
    return row_coordinate;
  }

  public int getColumn()
  {
    return column_coordinate;
  }
}
