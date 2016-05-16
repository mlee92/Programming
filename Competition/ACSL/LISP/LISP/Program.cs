using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LISP
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                {
                    Console.WriteLine("Enter Input Line 1: \n");
                    string q1 = Console.ReadLine();


                    LISPList Q1 = ParseString(q1);
                    Q1.PositionOrder();
                    Q1.ReversePosition();
                    Console.WriteLine(Q1.Print());
                    Console.WriteLine(Q1.Container.Count);

                    foreach (Atom obj in Q1.Container)
                    {
                        Console.WriteLine(obj.Value + " " + obj.Position);
                    }
                }
                {
                    Console.WriteLine("Enter Input Line 2: \n");
                    string q2 = Console.ReadLine();

                    LISPList Q2 = ParseString(q2);
                    Q2.Collect();
                    Console.WriteLine(Q2.Print());
                }
                {
                    Console.WriteLine("Enter Input Line 3: \n");
                    string q3 = Console.ReadLine();

                    LISPList Q3 = ParseString(q3);
                    Q3.Collect();
                    Console.WriteLine(Q3.Print());
                }
                {
                    Console.WriteLine("Enter Input Line 4: \n");
                    string q4 = Console.ReadLine();

                    LISPList Q4 = ParseString(q4);
                    int mod = Convert.ToInt32(Q4.Container.Last().Value);
                    Q4.Container.Remove(Q4.Container.Last());
                    Q4.DeleteMod(mod);
                    Q4.Append(new Atom(mod.ToString(), 0, Q4.Container.Count - 1));
                    Console.WriteLine(Q4.Print());
                }
                {
                    Console.WriteLine("Enter Input Line 5: \n");
                    string q5 = Console.ReadLine();

                    LISPList Q5 = ParseString(q5);
                    int start = Convert.ToInt32(Q5.Container.Last().Value);
                    Q5.Separate(start);
                    Console.WriteLine(Q5.Print());
                }
            }
            while(true)
            {
                System.Threading.Thread.Sleep(1);
                
            }
        }

        static LISPList ParseString(string data)
        {
            data = data.Remove(0, 2);
            data = data.Remove(data.Length - 1);
            string[] split = data.Split(" ".ToArray());
            
            int position = 0;
            LISPList Ret = new LISPList();
            foreach(string Obj in split)
            {
               Ret.Append(new Atom(Obj, 0, position));
                position++;
            }
            Ret.PositionOrder();
            return Ret;
        }
    }
}
