using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    public class ConditionalVelocityAction : Action
    {
        public int FirstBodyPart = 0;
        public int VelocityRelationship = 0;//greater than / less than
        public int ConditionalBodyPart = 0;
        public int ConditionRelationship = 0;//towards / away
        public float RelationshipValue = 0;
        public AndAction PassAction = null;

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

            streamWrite.WriteLine( "ActionType:ConditionalVelocity" );
            streamWrite.WriteLine( "ActionName:" + this.Name );
            streamWrite.WriteLine( "Timeout:" + this.Timeout );
            streamWrite.WriteLine( "FBP:" + FirstBodyPart );
            streamWrite.WriteLine( "VelocityRelation:" + VelocityRelationship );
            streamWrite.WriteLine( "ConditionBP:" + ConditionalBodyPart );
            streamWrite.WriteLine( "ConditionalRelationship:" + ConditionRelationship );
            streamWrite.WriteLine( "VelocityValue:" + RelationshipValue );

            PassAction.Serialise( streamWrite, true );

            streamWrite.WriteLine( "-----End-----" );
        }
    }
}
