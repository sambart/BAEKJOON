using System;

namespace Toss5
{
    class Program
    {
        static void Main(string[] args)
        {
            string input;
            input = Console.ReadLine();
            string[] split = input.Split(' ');

            string input2;
            input2 = Console.ReadLine();
            string[] split2 = input2.Split(' ');

            int retMoney = 0;
            for(int i=0;i<split.Length;i++)
            {
                int kimT = Convert.ToInt32(split[i]);
                int leeT = Convert.ToInt32(split2[i]);

                retMoney += kimT;
                retMoney -= leeT;

                if (retMoney <= 0)
                {
                    Console.Write("0");
                }
                else
                {
                    Console.Write(retMoney.ToString());
                    retMoney = 0;
                }
                if (i != split.Length - 1)
                    Console.Write(" ");
            }
        }
    }
}
