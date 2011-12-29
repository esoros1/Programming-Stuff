import java.util.HashSet;
import java.util.Iterator;

public class Runner
{
	
	public static void main(String [] args)
	{
		HashSet<Triangle> triangleSet = generateSet(500);
		System.out.println(triangleSet.size());
	}

	//generate an n by n grid that has all of the possible Triangles with one point fixed on
	//the origin
	public static HashSet<Triangle> generateSet(int n)
	{
		final int MAX_X = n-1;
		final int MAX_Y = n-1;
		final Point ORIGIN = new Point(0,0);
		final Point END_POINT = new Point(-1,-1);
		HashSet<Triangle> result = new HashSet<Triangle>();
		
		//we have one point that is "fixed", and another point that moves along all possible points.
		//then we move the the point over one and try again
		Point fixed = new Point(0,1);
		Point moving = new Point(1,0);
		
		while( !fixed.equals(END_POINT))
		{	
			//System.out.println("Fixed: " + fixed);
			while( !moving.equals(END_POINT))
			{
				//System.out.println("Moving: " +moving);
				Triangle temp = new Triangle(ORIGIN,fixed,moving);
				if(temp.isRightTriangle() && temp.isValidTriangle())	
					result.add(temp);
				moving = getNextValidPoint(moving, n);
			}
			fixed = getNextValidPoint(fixed, n);
			moving = new Point(1,0);
		}
	
		return result;
	}

	//get the next valid point in an n by n grid, starting at point p.
	//return (-1,-1) if there are no other points left
	public static Point getNextValidPoint(Point p,int n)
	{
		final int MAX_X = n-1;
		final int MAX_Y = n-1;
		
		Point result = null; 
		
		if(p.getX() < MAX_X && p.getY() < MAX_Y)
		{
			result = new Point(p.getX()+1, p.getY());
		}
		else if(p.getX() < MAX_X && p.getY() == MAX_Y)
		{
			result = new Point(p.getX()+1, p.getY());
		}
		else if(p.getX() >= MAX_X && p.getY() < MAX_Y)
		{
			result = new Point(0,p.getY()+1);
		}
		else if(p.getX() >= MAX_X && p.getY() >= MAX_Y)
		{
			result = new Point(-1,-1);
		}
		
		return result;
	}

}
