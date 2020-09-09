using System;
using System.Collections.Generic;

namespace Toss2
{
    class Program
    {
        static void Main(string[] args)
        {

			string input;
			input = Console.ReadLine();
			string[] split = input.Split(' ');
			bool[] isAccess = new bool[45];
			for (int i = 0; i < 45; i++)
			{
				isAccess[i] = false;
			}

			if(split.Length != 6)
            {
				Console.WriteLine("false");
				return;
            }


			for (int i = 0; i < 6; i++)
			{
				
				if (i > 0)
				{
					int a = Convert.ToInt32(split[i]);
					if(a > 45)
                    {
						Console.WriteLine("false");
						return;
					}
					/*
					if(isAccess[a])
					{
						Console.WriteLine("false");
						return;
					}
					isAccess[a] = true;
					*/
					int b = Convert.ToInt32(split[i - 1]);
					if (b >= a)
					{
						Console.WriteLine("false");
						return;
					}
				}
			}


			Console.WriteLine("true");

		}
	}
}
