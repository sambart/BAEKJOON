using System;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices.WindowsRuntime;

namespace tossCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();

            if(Compare(input))
            {
                Console.WriteLine("true");
            }
            else
            {
                Console.WriteLine("false");
            }
        }

        static bool Compare(string input)
        {

            for(int i=0;i<input.Length;i++)
            {
                char a = input[i];
                if (input[i] != '1' && input[i] != '2')
                {
                    return false;
                }

                if (input.Length - 1 != i)
                {
                    if (input[i] == '1')
                    {
                        if (input[i + 1] != '2')
                            return false;
                    }
                }
                else
                {
                    if (input[i] == '1')
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }
}
