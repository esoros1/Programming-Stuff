public class Triangle
{
	private Point p1, p2, p3;
	
	public Triangle()
	{
		p1 = new Point();
		p2 = new Point();
		p3 = new Point();
	}
	//I need to use a c++ style constructor, because the points inside the triangle will be changing.
	//this makes sure that the value of the point will not change.
	public Triangle(Point p1, Point p2, Point p3)
	{
		this.p1 = new Point(p1.getX(), p1.getY());
		this.p2 = new Point(p2.getX(), p2.getY());
		this.p3 = new Point(p3.getX(), p3.getY());
	}

	//The order of the points do not matter, so adding the point's hashes will do
	@Override
	public int hashCode()
	{
		return p1.hashCode() + p2.hashCode() + p3.hashCode();
	}

	//because the order of the points does not mater, we have to check 3!, or 6 differnet
	//poissible permutations for equality
	@Override
	public boolean equals(Object obj)
	{
		Triangle rhs = (Triangle) obj;
		
		if(p1.equals(rhs.p1)  && p2.equals(rhs.p2) && p3.equals(rhs.p3))
		{
			return true;
		}
		else if(p1.equals(rhs.p1) && p2.equals(rhs.p3) && p3.equals(rhs.p2))
		{
			return true;
		}
		else if(p1.equals(rhs.p2) && p2.equals(rhs.p1) && p3.equals(rhs.p3))
		{
			return true;
		}
		else if(p1.equals(rhs.p2) && p2.equals(rhs.p3) && p3.equals(rhs.p1))
		{
			return true;
		}
		else if(p1.equals(rhs.p3) && p2.equals(rhs.p1) && p3.equals(rhs.p2))
		{
			return true;
		}
		else if(p1.equals(rhs.p3) && p2.equals(rhs.p2) && p3.equals(rhs.p1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	@Override
	public String toString()
	{
		return p1.toString() + " " + p2.toString() +  " " + p3.toString();
	}
	
	//if the triangle has a right angle, than the dot product of two of the sides will be zero
	//we need to check all three sides, and convert all the points into vectors
	public boolean isRightTriangle()
	{
		Vector v1 = new Vector(p1,p2);
		Vector v2 = new Vector(p1,p3);
		Vector v3 = new Vector(p2,p3);
		
		if(v1.dotProduct(v2) == 0 || v1.dotProduct(v3) == 0 || v2.dotProduct(v3) == 0)
		{
			return true;
		}
		
		return false;
	}

	//we need to check to make sure that the points aren't on a straight on line (not a triangle)
	//and that two of the points are not the same
	public boolean isValidTriangle()
	{
		if (p1.getX() == p2.getX() && p2.getX() == p3.getX())
		{
			return false;
		}
		if(p1.getY() == p2.getY() && p2.getY() == p3.getY())
		{
			return false;
		}
		if(p1.equals(p2) || p1.equals(p3) || p2.equals(p3))
		{
			return false;
		}
		
		return true;
	}
}
