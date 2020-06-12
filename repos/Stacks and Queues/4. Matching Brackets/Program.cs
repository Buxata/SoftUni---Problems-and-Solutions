using System;
using System.Collections.Generic;

namespace Brackets
{
    class Program
    {
        
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            Stack<int> positions = new Stack<int>();

            for (int i = 0; i < input.Length; i++)
            {
                switch (input[i])
                {
                    case '(':
                        positions.Push(i);
                        break;
                    case ')':
                        int temp = positions.Pop();
                        Console.WriteLine(input.Substring(temp, (i-temp+1)));
                        break;
                }
            }
        }
    }
}
