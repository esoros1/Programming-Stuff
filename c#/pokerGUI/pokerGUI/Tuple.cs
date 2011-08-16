using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace poker
{
    //A simple tuple class
    //I know that c# already has one built in, but i wanted to test generics out
    class TwoTuple<T,U>
    {
        private T firstData;
        private U secondData;

        public TwoTuple(T t, U u) { firstData = t; secondData = u; }
        public T getFirst() { return firstData; }
        public U getSecond() { return secondData; }
        public void setFirst(T t) { firstData = t; }
        public void setSecond(U u) { secondData = u; }
        
        public override string ToString() { return firstData.ToString() + " " + secondData.ToString(); }
      
    }
}
