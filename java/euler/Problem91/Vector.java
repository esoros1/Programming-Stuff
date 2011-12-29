public class Vector
{
	//a geometric vector
	private int x,y;

	public Vector()
	{
		x = 0;
		y = 0;
	}

	public Vector(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public Vector(Point p1, Point p2)
	{
		this.x = p2.getX() - p1.getX();
		this.y = p2.getY() - p1.getY();
	}


	public int dotProduct(Vector rhs)
	{
		return x * rhs.x + y * rhs.y;
	}

	@Override
	public String toString()
	{
		return "( "+ x +", "+ y + " )";
	}
}
