using System;
using System.Collections.Generic;

namespace Simple_Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            
            string input = Console.ReadLine();
            Stack<int> posNumbers = new Stack<int>();
            Stack<int> negNumbers = new Stack<int>();
            if (input[0] != '-') posNumbers.Push(ReadInput(input,0));
            for (int i = 0; i < input.Length; i++)
            {
                
                char check = input[i];
                switch (check)
                {
                    case '+':
                        posNumbers.Push(ReadInput(input, ( i + 2 )));
                        break;
                    case '-':
                        negNumbers.Push(ReadInput(input, ( i + 2 )));
                        break;
                    default:
                        break;
                }
            }
            int sum =0;
            foreach (int num in posNumbers)
            {
                sum += num;
            }
            foreach (int num in negNumbers)
            {
                sum -= num;
            }
            Console.WriteLine(sum);

        }
        static int ReadInput (string inp, int start)
        {
            inp += " ";
            string temp ="";
            while (inp[start] != ' ' && start < inp.Length)
            {
                temp += inp[start];
                start++;
            }
            return int.Parse(temp);
        }

    }
}
