using System;
using System.Collections.Generic;

namespace Toss4
{
    class Program
    {
        static void Main(string[] args)
        {

            string input;
            input = Console.ReadLine();
            string[] split = input.Split(' ');

            List<string> inputList = new List<string>();

            foreach(string inp in split)
            {
                if(inputList.Contains(inp))
                {
                    inputList.Remove(inp);
                }
                inputList.Add(inp);


                PrintList(inputList);
            }

        }

        static void PrintList(List<string> strList)
        {
            int cnt = 0;
            for (int i = strList.Count -1; i >= 0; i--)
            {
                if (cnt == 5)
                {
                    Console.WriteLine();
                    return;
                }

                if (i != strList.Count -1)
                    Console.Write(" ");
                Console.Write(strList[i]);
                cnt++;
            }

            Console.WriteLine();
        }
    }
}
