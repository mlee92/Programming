using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LISP
{
    class Atom
    {
        public string Value;
        public int Count;
        public int Position;

        public Atom(string val, int count, int position)
        {
            Value = val;

            Count = count;
            Position = position;
        }

        public string Print()
        {
            string ret = "";
            if(Count > 0)
            {
                ret += "(" + Count + " ";
            }
            ret += Value.ToString();
            if(Count > 0)
            {
                ret += ")";
            }
            return ret;
        }

        public string PrintSingleton()
        {
            string ret = "";
            if(Count != 1)
            {
                return Print();
            }
            else
            {
                return Value.ToString();
            }
        }
    }
}
