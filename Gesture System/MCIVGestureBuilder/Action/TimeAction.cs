using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    public class TimeAction : Action
    {
        public float TimeToPass = 0.0f; 

        public TimeAction()
        {

        }

        public override void Serialise( StreamWriter streamWrite, bool innerAction = false )
        {
            if ( !innerAction )
            {
                streamWrite.WriteLine( "-----Action-----" );
            }
            else
            {
                streamWrite.WriteLine( "-----InnerAction-----" );
            }

            streamWrite.WriteLine( "ActionType:Time" );
            streamWrite.WriteLine( "ActionName:" + this.Name );
            streamWrite.WriteLine( "Timeout:" + this.Timeout );
            streamWrite.WriteLine( "TimeToPass:" + this.TimeToPass );

            streamWrite.WriteLine( "-----End-----" );
            
        }


    }
}
