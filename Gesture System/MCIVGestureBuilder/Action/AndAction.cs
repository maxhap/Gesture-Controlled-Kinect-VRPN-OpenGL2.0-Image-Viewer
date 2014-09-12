using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    public class AndAction : Action
    {
        List<Action> _ActionList = new List<Action>();

        public List<Action> GetActions()
        {
            return _ActionList;
        }

        public Action GetAction( string name )
        {
            foreach ( Action action in _ActionList )
            {
                if ( action.Name == name )
                {
                    return action;
                }
            }

            return null;
        }

        public void AddAction( Action action )
        {
            _ActionList.Add( action );
        }

        public void ReplaceAction( Action oldAction, Action newAction )
        {
            if ( _ActionList.Contains( oldAction ) )
            {
                int index = _ActionList.IndexOf( oldAction );
                _ActionList.Remove( oldAction );
                _ActionList.Insert( index, newAction );
            }
        }

        public void RemoveAction( string actionName )
        {
            Action actionRemove = null;

            foreach ( Action action in _ActionList )
            {
                if ( action.Name == actionName )
                {
                    actionRemove = action;
                }
            }

            if ( actionRemove != null )
            {
                _ActionList.Remove( actionRemove );
            }
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

            streamWrite.WriteLine( "ActionType:And"  );
            streamWrite.WriteLine( "ActionName:" + this.Name );
            streamWrite.WriteLine( "Timeout:" + this.Timeout );

            foreach ( Action action in _ActionList )
            {
                action.Serialise( streamWrite, true );
            }

            streamWrite.WriteLine( "-----MultiEnd-----" );
        }
    }
}
