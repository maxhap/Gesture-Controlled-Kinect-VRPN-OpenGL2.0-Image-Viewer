using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MCIVGestureBuilder
{
    class Gesture
    {
        private string _sGestureName = string.Empty;
        private List<Action> _ActionList = new List<Action>();

        public Gesture( string sName )
        {
            _sGestureName = sName;
        }

        public string GestureName
        {
            get { return _sGestureName; }
            set { _sGestureName = value; }
        }

        public void AddAction( Action action )
        {
            _ActionList.Add( action );
        }

        public void AddActionAt( int index, Action action )
        {
            _ActionList.Insert( index, action );
        }

        public void RemoveAction( string sAction )
        {
            Action actionRemove = null;

            foreach ( Action action in _ActionList )
            {
                if ( action.Name == sAction )
                {
                    actionRemove = action;
                    break;
                }
            }

            if ( actionRemove != null )
            {
                _ActionList.Remove( actionRemove );
            }
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

        public List<Action> GetActions()
        {
            return _ActionList;
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

        public void Serialise( StreamWriter streamWriter )
        {
            streamWriter.WriteLine( "-----------------Gesture------------------" );
            streamWriter.WriteLine( "GestureName:" + _sGestureName );

            foreach ( Action action in _ActionList )
            {
                action.Serialise( streamWriter );
            }

            streamWriter.WriteLine( "-----------------End------------------" );
        }
    }
}
