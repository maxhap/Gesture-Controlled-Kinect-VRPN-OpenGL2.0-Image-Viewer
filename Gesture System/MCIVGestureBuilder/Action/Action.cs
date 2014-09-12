using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    public class Action
    {
        public string Name;
        public float Timeout;

        public virtual void Serialise( StreamWriter streamWrite, bool innerAction = false )
        {

        }
    }    
}
