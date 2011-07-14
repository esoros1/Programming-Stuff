import java.util.HashSet;
import java.util.Iterator;

public class Problem61
{
	public static HashSet<Integer> squareSet = new HashSet<Integer>();
	public static HashSet<Integer> triSet = new HashSet<Integer>();
	public static HashSet<Integer> hexSet = new HashSet<Integer>();
	public static HashSet<Integer> heptSet = new HashSet<Integer>();
	public static HashSet<Integer> octSet = new HashSet<Integer>();
	public static HashSet<Integer> pentSet = new HashSet<Integer>();

	//does it have one from each of the groups
	public static boolean hasAllSix(int num1, int num2, int num3, int num4, int num5, int num6)
	{
		boolean square = false, tri = false, hex = false, hept = false, oct = false, pent = false;
		int [] nums = {num1,num2,num3,num4,num5,num6};

		for(int i = 0; i < 6; ++i)
		{
			int num = nums[i];
			boolean found = false;
			if(squareSet.contains(num) && !square && !found)
			{
				square = true;
				found = true;
			}
			if(triSet.contains(num) && !tri && !found)
			{
				tri = true;
				found = true;
			}
			if(hexSet.contains(num) && !hex && !found)
			{
				hex = true;
				found = true;
			}
			if(heptSet.contains(num) && !hept && !found)
			{
				hept = true;
				found = true;
			}
			if(octSet.contains(num) && !oct && !found)
			{
				oct = true;
				found = true;
			}
			if(pentSet.contains(num) && !pent && !found)
			{
				pent = true;
				found = true;
			}
		}
		return square && tri && hex && hept && oct && pent;
	}

	public static void main(String [] args)
	{
//		int k = 3; 
//		int n = getOctagonal(k);
//		while (n < 1000)
//			n = getOctagonal(++k);
//		System.out.println(Integer.valueOf(k).toString()+" "+Integer.valueOf(n).toString());

		HashSet<Integer> nums = new HashSet<Integer>();

		//trianle numbers from n = 45 - 140
		for(int i = 45; i <= 140; ++i)
		{
			Integer num = getTriangle(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				triSet.add(num);
			}
		}
//		square numbers from n = 32 - 99
		for(int i = 32; i <= 99; ++i)
		{	
			Integer num = getSquare(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				squareSet.add(num);
			}
		}

		//pentagonal numbers from n = 26 - 81
		for(int i = 26; i <= 81; ++i)
		{
			Integer num = getPentagonal(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				pentSet.add(num);
			}
		}

		//hexagonal nmbers from n = 23 - 70
		for(int i = 23; i <= 70; ++i)
		{
			Integer num = getHexagonal(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				hexSet.add(num);
			}
		}
		
		//heptagonal nmbers from n = 21 - 63
		for(int i = 21; i <= 63; ++i)
		{
			Integer num = getHeptagonal(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				heptSet.add(num);
			}
		}

		//Octagonal nmbers from n = 19 - 58
		for(int i = 19; i <= 58; ++i)
		{
			Integer num = getOctagonal(i);
			int firstNum = Integer.parseInt(num.toString().substring(0,2));
			int secondNum = Integer.parseInt(num.toString().substring(2,4));
			if (firstNum > 9 && firstNum % 10 != 0 && secondNum > 9 && secondNum % 10 != 0)
			{
				nums.add(num);
				octSet.add(num);
			}
		}

		Iterator num1Itor = nums.iterator();
		while(num1Itor.hasNext())
		{
			//check to see if we have a repeat
			Integer num1 = (Integer)num1Itor.next();
			Iterator num2Itor = nums.iterator();
			while(num2Itor.hasNext())
			{
				Integer num2 = (Integer)num2Itor.next();
				//is it cyclic?
				if( Integer.parseInt(num1.toString().substring(2,4)) == 
				Integer.parseInt(num2.toString().substring(0,2)) )
				{
					Iterator num3Itor = nums.iterator();
					while(num3Itor.hasNext())
					{
						Integer num3 = (Integer)num3Itor.next();
						if( !num3.equals(num2) && !num3.equals(num1) )
						{
							if( Integer.parseInt(num2.toString().substring(2,4)) == 
							Integer.parseInt(num3.toString().substring(0,2)) )
							{
								Iterator num4Itor = nums.iterator();
								while(num4Itor.hasNext())
								{
									Integer num4 = (Integer)num4Itor.next();
									if (!num4.equals(num1) && !num4.equals(num2) && !num4.equals(num3))
									{
										if( Integer.parseInt(num3.toString().substring(2,4)) == 
										Integer.parseInt(num4.toString().substring(0,2)) )
										{
											Iterator num5Itor = nums.iterator();
											while(num5Itor.hasNext())
											{
												Integer num5 = (Integer)num5Itor.next();
												if(!num5.equals(num1) && !num5.equals(num2) && !num5.equals(num3) && !num5.equals(num4))
												{
													if( Integer.parseInt(num4.toString().substring(2,4)) == 
													Integer.parseInt(num5.toString().substring(0,2)) )
													{
														Iterator num6Itor = nums.iterator();
														while(num6Itor.hasNext())
														{
															Integer num6 = (Integer)num6Itor.next();
															if (!num6.equals(num1) && !num6.equals(num2) && !num6.equals(num3) &&
															!num6.equals(num4) && !num6.equals(num5) )
															{
																if( Integer.parseInt(num5.toString().substring(2,4)) == 
																Integer.parseInt(num6.toString().substring(0,2))  &&
																Integer.parseInt(num6.toString().substring(2,4)) == 
																Integer.parseInt(num1.toString().substring(0,2)))
																{
																	if(hasAllSix(num1,num2,num3,num4,num5,num6))
																	System.out.println(num1+num2+num3+num4+num5+num6);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//get the nth triangle number
	public static int getTriangle(int n) {return n * (n+1) / 2;}
	//get the nth sqaure number
	public static int getSquare(int n) {return n * n;}
	//et the nth pentaonal number
	public static int getPentagonal(int n) {return n * (3*n-1) / 2;}
	//get the nth hexagonal number
	public static int getHexagonal(int n) {return n * (2*n -1);}
	//get the nth heptagonal number
	public static int getHeptagonal(int n) {return n * (5*n - 3) / 2;}
	//get the nth octagonal number
	public static int getOctagonal(int n) { return n * (3*n - 2);}
}
