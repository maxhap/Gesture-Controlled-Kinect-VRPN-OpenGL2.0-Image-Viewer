using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace MCIVGestureBuilder
{
    public class PositionAction : Action
    {        
        public int FirstBodyPart;
        public int Relationship;
        public int SecondBodyPart;
        public float UpperBoundsRelationshipValue;
        public float LowerBoundsRelationshipValue;

        public override void Serialise( StreamWriter streamWrite, bool innerAction = false )
        {
            if( !innerAction )
            {
                streamWrite.WriteLine( "-----Action-----" );
            }
            else
            {
                streamWrite.WriteLine( "-----InnerAction-----" );
            }

            streamWrite.WriteLine( "ActionType:Position" );
            streamWrite.WriteLine( "ActionName:" + this.Name );
            streamWrite.WriteLine( "Timeout:" + this.Timeout );
            streamWrite.WriteLine( "FBP:" + FirstBodyPart );           
            streamWrite.WriteLine( "Relation:" + Relationship );
            streamWrite.WriteLine( "SBP:" + SecondBodyPart );
            streamWrite.WriteLine( "UpperBoundsValue:" + UpperBoundsRelationshipValue );
            streamWrite.WriteLine( "LowerBoundsValue:" + LowerBoundsRelationshipValue );

            streamWrite.WriteLine( "-----End-----" );
        }
    }
}
