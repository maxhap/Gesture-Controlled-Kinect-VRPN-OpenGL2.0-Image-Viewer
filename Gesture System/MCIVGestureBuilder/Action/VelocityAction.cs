using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    public class VelocityAction : Action
    {
        public int FirstBodyPart;
        public int Relationship;
        public float RelationshipValue;

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

            streamWrite.WriteLine( "ActionType:Velocity" );
            streamWrite.WriteLine( "ActionName:" + this.Name );
            streamWrite.WriteLine( "Timeout:" + this.Timeout );
            streamWrite.WriteLine( "FBP:" + FirstBodyPart );
            streamWrite.WriteLine( "Relation:" + Relationship );
            streamWrite.WriteLine( "Value:" + RelationshipValue );

            streamWrite.WriteLine( "-----End-----" );
        }
    }
}
