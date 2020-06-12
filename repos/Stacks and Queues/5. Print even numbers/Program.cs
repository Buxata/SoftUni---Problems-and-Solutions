using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;

namespace Print_even_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var numbers = new Queue<int>();

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] != ' ')
                {
                    string temp = ReadString(input, i);
                    numbers.Enqueue(int.Parse(temp));
                    i += temp.Length;
                }
            }

            int counter = numbers.Count;
            for (int i = 1; i <= counter; i++)
            {
                int temp = numbers.Dequeue();
                if (temp%2 == 0)
                {
                    Console.Write(temp);
                    if (i != counter) Console.Write(", ");
                }
            }
        }
        static string ReadString(string inp, int n)
        {
            inp += " ";
            string temp ="";
            while (inp[n] != ' ' && n < inp.Length)
            {
                temp += inp[n];
                n++;
            }
            return temp;
        }
    }
}
