using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.Serialization;

namespace Stack_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            Stack<int> numbers = new Stack<int>();

            for (int i = 0; i < input.Length; i++)
            {
                if (input [i] != ' ')
                {
                    string temp = ReadString(input, i);
                    numbers.Push(int.Parse(temp));
                    i += temp.Length;
                }
            }

            while (input.ToLower() != "end")
            {
                input = Console.ReadLine();
                
                switch (ReadString(input, 0).ToLower())
                {
                    case "add":
                        int tempNum = ReadString(input,(ReadString(input,0).Length +1)).Length + 5;
                        numbers.Push(int.Parse(ReadString(input, (ReadString(input, 0).Length + 1))));
                        numbers.Push(int.Parse(ReadString(input, tempNum)));
                        break;
                    case "remove":
                        int counter = (int.Parse(ReadString(input, ( ReadString(input, 0).Length + 1 ))));
                        if (counter <= numbers.Count)
                        {
                            while (counter > 0)
                            {
                            numbers.Pop();
                            counter--;
                            }
                        }

                        break;
                    case "end":
                        int sum =0;
                        foreach (int num in numbers)
                        {
                            sum += num;
                        }
                        Console.WriteLine($"Sum: {sum}");
                        break;
                    case "pop":
                        Console.WriteLine(numbers.Pop());
                        break;
                    default:
                        break;
                }
                
            }

        }
        static string ReadString (string inp, int n)
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
