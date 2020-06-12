using System;
using System.Collections.Generic;

namespace Reverse_Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            Stack<char> reverseMe = new Stack<char>();
            


            for (int i = 0; i<input.Length; i++ )
            {

                reverseMe.Push(input[input.Length - i - 1]);
                Console.Write(reverseMe.Pop());
            }               
        }
    }
}
