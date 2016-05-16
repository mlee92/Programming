using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LISP
{
    class LISPList
    {
        public List<Atom> Container;

        public LISPList()
        {
            Container = new List<Atom>();
        }

        public void Append(Atom Obj)
        {
            // Obj.Position = Position; 
            Container.Add(Obj);
        }

        public void PositionOrder()
        {
            Regroup();
            Atom[] Dummy = new Atom[Container.Count];
            foreach(Atom Obj in Container)
            {
                Dummy[Obj.Position] = Obj;
            }
            Container.Clear();
            int position = 0;
            foreach(Atom Obj in Dummy)
            {
                if (Obj != null)
                {
                    Obj.Position = position;
                    Append(Obj);
                    position++;
                }
            }
        }

        public void Separate(int start)
        {
            PositionOrder();
            List<Atom> Dummy = Container.ToList();
            LISPList List1 = new LISPList(), List2 = new LISPList();
            Container.Clear();
            for(int i = 0; i < start; i++)
            {
                Dummy[i].Position = i;
                List1.Append(Dummy[i]);
            }
            for(int k = start; k < Dummy.Count; k++)
            {
                Dummy[k].Position = k - start;
                List2.Append(Dummy[k]);
            }
            List1.PositionOrder();
            List2.PositionOrder();
            Append(new Atom(List1.Print().Remove(0,2), 0, 0));
            Append(new Atom(List2.Print().Remove(List2.Print().Length - 1), 0, 1));
            PositionOrder();
        }

        public void Regroup()
        {
            List<Atom> Dummy = Container.ToList();
            Container.Clear();
            int index = 0,  skip = 1,  position = 0;
            while(index + skip <= Dummy.Count)
            {
                string value = Dummy[index].Value;
                try
                {
                    
                        if( Dummy[index].Value.Contains("(")&&!Dummy[index].Value.Contains(")"))
                        {
                            value = Dummy[index].Value + " " + Dummy[index + 1].Value;
                            skip++;
                        }
                
                } catch
                {
                    // Do nothing
                }
                value.Replace("(", "");
                value.Replace(")", ""); 
                Append(new Atom(value, 0, position));
                index += skip;
                skip = 1;
                position++;
            }
        }
        
        public void Collect()
        {
            PositionOrder();
            List<Atom> Dummy = Container.ToList();
            Container.Clear();
            int index = 0, copies = 1, n = 0;
            while(index + copies <= Dummy.Count)
            {
                try
                {
                    while (Dummy[index].Value.Equals((Dummy[index + copies].Value)))
                    {
                        copies++;
                    }
                } catch
                {
                    // Do nothing, index out of bounds, obvious
                }
                Append(new Atom(Dummy[index].Value, copies, n));
                index += copies;
                copies = 1;
                n++;
            }
            
            PositionOrder();
        }

        public void DeleteMod(int modulus)
        {
            PositionOrder();
            List<Atom> Dummy = Container;
            Container.Clear();
            int position = 0;
            foreach(Atom Obj in Dummy)
            {
                if(Obj.Position + 1 % modulus != 0)
                {
                    Obj.Position = position;
                    Append(Obj);
                    position++;
                }
            }
        }

        public void ReversePosition()
        {
            int length = Container.Count - 1;
            foreach(Atom Obj in Container)
            {
                Obj.Position = length - Obj.Position;
            }
            PositionOrder();
        }

        public string Print()
        {
            string ret = "'(";
            for (int i = 0; i < Container.Count; i++)
            {
                ret += Container[i].Print();
                if(i == Container.Count - 1)
                {
                    ret += ")";
                } else
                {
                    ret += " ";
                }
            }
            return ret;
        }
    }
}
