using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace MCIVGestureBuilder
{
    public partial class MainWnd : Form
    {
        private List<Skeliton> _Skelitons = new List<Skeliton>();

        public MainWnd()
        {
            InitializeComponent();

            CBActionType.SelectedIndex = 0;
        }

        private void Form1_Load( object sender, EventArgs e )
        {
            this.MaximizeBox = false;

            //build skeliton list
            Skeliton skel = new Skeliton();
            skel.ID = 0;
            _Skelitons.Add( skel );

            skel = new Skeliton();
            skel.ID = 1;
            _Skelitons.Add( skel );

            skel = new Skeliton();
            skel.ID = 2;
            _Skelitons.Add( skel );

            skel = new Skeliton();
            skel.ID = 3;
            _Skelitons.Add( skel );

            LoadGestureTree();
        }

        private void LoadGestureTree()
        {            
            TreeNode tnAdd = new TreeNode( "Gestures" );
            TVGesturesSkel1.Nodes.Add( tnAdd );

            TreeNode node0 = new TreeNode( "Skeleton 0" );
            
            ContextMenuStrip ms = new ContextMenuStrip();
            ToolStripMenuItem mi = new ToolStripMenuItem( "New" );
            mi.Click += new EventHandler( NewGesture0_Click );
            ms.Items.Add( mi );                       
            node0.ContextMenuStrip = ms;

            TVGesturesSkel1.Nodes[0].Nodes.Add( node0 );

            TreeNode node1 = new TreeNode( "Skeleton 1" );

            ms = new ContextMenuStrip();
            mi = new ToolStripMenuItem( "New" );
            mi.Click += new EventHandler( NewGesture1_Click );
            ms.Items.Add( mi );
            node1.ContextMenuStrip = ms;

            TVGesturesSkel1.Nodes[0].Nodes.Add( node1 );

            TreeNode node2 = new TreeNode( "Skeleton 2" );

            ms = new ContextMenuStrip();
            mi = new ToolStripMenuItem( "New" );
            mi.Click += new EventHandler( NewGesture2_Click );
            ms.Items.Add( mi );
            node2.ContextMenuStrip = ms;

            TVGesturesSkel1.Nodes[0].Nodes.Add( node2 );

            TreeNode node3 = new TreeNode( "Skeleton 3" );

            ms = new ContextMenuStrip();
            mi = new ToolStripMenuItem( "New" );
            mi.Click += new EventHandler( NewGesture3_Click );
            ms.Items.Add( mi );
            node3.ContextMenuStrip = ms;

            TVGesturesSkel1.Nodes[0].Nodes.Add( node3 );

            TVGesturesSkel1.ExpandAll();  
        }

        private void NewGesture0_Click( object sender, EventArgs e )
        {            
            string sName = GetGestureName();

            if( sName != "" )
            {
                _Skelitons[0].GestureList.Add( new Gesture( sName ) );

                AddNodeToTree( 0, sName );
            }                        
        }

        private void NewGesture1_Click( object sender, EventArgs e )
        {
            string sName = GetGestureName();

            if ( sName != "" )
            {
                _Skelitons[1].GestureList.Add( new Gesture( sName ) );

                AddNodeToTree( 1, sName );
            }
        }

        private void NewGesture2_Click( object sender, EventArgs e )
        {
            string sName = GetGestureName();

            if ( sName != "" )
            {
                _Skelitons[2].GestureList.Add( new Gesture( sName ) );

                AddNodeToTree( 2, sName );
            }
        }

        private void NewGesture3_Click( object sender, EventArgs e )
        {
            string sName = GetGestureName();

            if ( sName != "" )
            {
                _Skelitons[3].GestureList.Add( new Gesture( sName ) );

                AddNodeToTree( 3, sName );
            }
        }

        private string GetGestureName()
        {
            Input input = new Input();

            if ( input.ShowDialog() == DialogResult.OK )
            {
                if ( input.GestureText.ToLower() == "gestures" || input.GestureText.ToLower() == "" )
                {
                    MessageBox.Show( "Sorry '" + input.GestureText +"' is a reserved gesture name, please try another" );
                    return "";
                }

                if ( NameTakenCheck( input.GestureText.ToLower() ) )
                {
                    MessageBox.Show( "Sorry '" + input.GestureText + "' is already assigned to another gesture" );
                    return "";
                }   

                return input.GestureText;
            }

            return "";
        }
        private void AddNodeToTree( int skeliton, string nodeText )
        {
            ContextMenuStrip ms = new ContextMenuStrip();

            ToolStripMenuItem miRename = new ToolStripMenuItem( "Rename" );
            miRename.Click += new EventHandler( RenameGesture_Click );
            ms.Items.Add( miRename );

            ToolStripMenuItem miNew = new ToolStripMenuItem( "Delete" );
            miNew.Click += new EventHandler( DeleteGesture_Click );
            ms.Items.Add( miNew );

            TreeNode tnAdd = new TreeNode( nodeText );
            tnAdd.ContextMenuStrip = ms;

            TVGesturesSkel1.Nodes[0].Nodes[skeliton].Nodes.Add( tnAdd );

            TVGesturesSkel1.ExpandAll();

            TVGesturesSkel1.SelectedNode = TVGesturesSkel1.Nodes[0].Nodes[skeliton].Nodes[TVGesturesSkel1.Nodes[0].Nodes[skeliton].Nodes.Count - 1];
        }

        private int GetSelectedNodeSkeliton()
        {
            if ( TVGesturesSkel1.SelectedNode.Level == 1 )
            {
                if ( TVGesturesSkel1.SelectedNode.Text.Contains( "0" ) ) return 0;
                if ( TVGesturesSkel1.SelectedNode.Text.Contains( "1" ) ) return 1;
                if ( TVGesturesSkel1.SelectedNode.Text.Contains( "2" ) ) return 2;
                if ( TVGesturesSkel1.SelectedNode.Text.Contains( "3" ) ) return 3;
            }
            else if( TVGesturesSkel1.SelectedNode.Level == 2 )
            {
                if( TVGesturesSkel1.SelectedNode.Parent.Text.Contains( "0" ) ) return 0;
                if ( TVGesturesSkel1.SelectedNode.Parent.Text.Contains( "1" ) ) return 1;
                if ( TVGesturesSkel1.SelectedNode.Parent.Text.Contains( "2" ) ) return 2;
                if ( TVGesturesSkel1.SelectedNode.Parent.Text.Contains( "3" ) ) return 3;
            }

            return -1;            
        }
        
        private void DeleteGesture_Click( object sender, EventArgs e )
        {            
            if ( TVGesturesSkel1.SelectedNode != null )
            {               
                Gesture gestureToRemove = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );
                
                if( gestureToRemove != null )
                {
                    _Skelitons[GetSelectedNodeSkeliton()].GestureList.Remove( gestureToRemove );
                }

                TVGesturesSkel1.SelectedNode.Remove();
            }
        }

        private void RenameGesture_Click( object sender, EventArgs e )
        {
            if ( TVGesturesSkel1.SelectedNode != null )
            {                
                string sNewName = GetGestureName();

                if ( sNewName != "" )
                {
                    Gesture gestureToChange = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );
                    gestureToChange.GestureName = sNewName;

                    TVGesturesSkel1.SelectedNode.Text = sNewName;

                    TBGName.Text = sNewName;
                }
            }
                
        }
        
        private bool NameTakenCheck( string name )
        {
            foreach ( Gesture gesture in _Skelitons[GetSelectedNodeSkeliton()].GestureList )
            {
                if ( gesture.GestureName == name.ToLower() )
                {
                    return true;
                }
            }

            return false;
        }

        private void BBuild_Click(object sender, EventArgs e)
        {
            if ( CBActionType.SelectedIndex == 0 )
            {
                BuildPositionAction bsp = new BuildPositionAction();

                if ( bsp.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), bsp.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 1 )
            {
                BuildVelocityAction velocityAction = new BuildVelocityAction();

                if ( velocityAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), velocityAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 2 )
            {
                ConditionalActionBuilder cAction = new ConditionalActionBuilder();

                if ( cAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), cAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 3)
            {
                BuildAndGesture andAction = new BuildAndGesture();

                if ( andAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), andAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 4 )
            {
                BuildOrGesture orAction = new BuildOrGesture();

                if ( orAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), orAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 5 )
            {
                BuildTimeAction timeAction = new BuildTimeAction();

                if ( timeAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( GetSelectedNodeSkeliton(), timeAction.Action );
                }
            }
            
        }

        private void AddAction( int skeliton, Action action )
        {
            Gesture currentGesture = GetGesture( skeliton, TVGesturesSkel1.SelectedNode.Text );

            if ( currentGesture != null )
            {
                if ( !LBActions.Items.Contains( action.Name ) )
                {
                    currentGesture.AddAction( action );
                    RebuildActionList();
                }
                else
                {
                    MessageBox.Show( "Sorry '" + action.Name + "' is already assigned to another action" );
                    return;
                }
            }
        }

        private Gesture GetGesture( int skeliton, string name )
        {
            Gesture gesture = null;
            
            foreach ( Gesture ges in _Skelitons[skeliton].GestureList )
            {
                if ( ges.GestureName == name )
                {
                    gesture = ges;
                }
            }

            return gesture;
        }

        private void splitContainer1_SplitterMoved( object sender, SplitterEventArgs e )
        {
            if ( splitContainer1.SplitterDistance > 400 )
            {
                splitContainer1.SplitterDistance = 400;
            }

            if ( splitContainer1.SplitterDistance < 200 )
            {
                splitContainer1.SplitterDistance = 200;
            }
        }

        private void TVGestures_AfterSelect( object sender, TreeViewEventArgs e )
        {
            if ( TVGesturesSkel1.SelectedNode.Level > 1 )
            {
                TBGName.Text = TVGesturesSkel1.SelectedNode.Text;
                RebuildActionList();
                panel2.Visible = true;
                label7.Visible = false;
                label2.Visible = true;
            }
            else
            {
                label7.Visible = true;
                panel2.Visible = false;
                label2.Visible = false;
            }
        }

        public void RebuildActionList()
        {
            Gesture gesture = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );

            if ( gesture != null )
            {
                LBActions.Items.Clear();

                foreach ( Action action in gesture.GetActions() )
                {
                    LBActions.Items.Add( action.Name );
                }
            }
        }

        private void exitToolStripMenuItem_Click( object sender, EventArgs e )
        {
            this.Close();
        }

        private void exportToolStripMenuItem_Click( object sender, EventArgs e )
        {
            Serialise();
        }

        private void Serialise()
        {
            SaveFileDialog saveDio = new SaveFileDialog();
            saveDio.Filter = "txt files (*.txt)|*.txt";

            if( saveDio.ShowDialog() == System.Windows.Forms.DialogResult.OK )
            {
                try
                {
                    StreamWriter streamWriter = new StreamWriter( saveDio.FileName );

                    foreach ( Skeliton skeliton in _Skelitons )
                    {
                        if ( skeliton.GestureList.Count > 0 )
                        {
                            streamWriter.WriteLine( "--------------------------------------------------------Skeliton-----------------------------------------------------" );
                            streamWriter.WriteLine( "ID:" + skeliton.ID );
                            foreach ( Gesture gesture in skeliton.GestureList )
                            {
                                gesture.Serialise( streamWriter );
                            }

                            streamWriter.WriteLine( "------------------------------------------------------End Skeliton---------------------------------------------------" );
                        }                        
                    }
                    

                    streamWriter.Close();
                }
                catch ( Exception e )
                {
                    MessageBox.Show( e.Message );
                }
            }
        }

        private void deleteActionsToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( TVGesturesSkel1.SelectedNode.Level < 1 )
            {
                return;
            }

            for ( int i = 0; i < LBActions.Items.Count; i++ )
            {
                Gesture gesture = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );
                gesture.RemoveAction( LBActions.Items[i].ToString() );
            }

            RebuildActionList();
        }

        private void BActionDelete_Click( object sender, EventArgs e )
        {
            if( LBActions.SelectedItem != null )
            {
                Gesture gesture = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );
                gesture.RemoveAction( LBActions.SelectedItem.ToString() );
                RebuildActionList();
            }
            else
            {
                MessageBox.Show( "Select an action to delete" );
            }
        }

        private void deleteAllGesturesToolStripMenuItem_Click( object sender, EventArgs e )
        {
            TVGesturesSkel1.Nodes[0].Nodes[0].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[1].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[2].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[3].Nodes.Clear();

            
            foreach ( Skeliton skel in _Skelitons )
            {
                skel.GestureList.Clear();
            }
            

            panel2.Visible = false;
        }

        private void TVGestures_MouseClick( object sender, MouseEventArgs e )
        {
            TreeNode node = TVGesturesSkel1.GetNodeAt( e.Location );
            TVGesturesSkel1.SelectedNode = node;
        }

        private void BEdit_Click( object sender, EventArgs e )
        {
            if ( LBActions.SelectedItem != null )
            {
                Gesture currentGesture = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );
                Action action =  currentGesture.GetAction( LBActions.SelectedItem.ToString() );
                Action updatedAction = null;

                if ( action.GetType().ToString().Contains( "PositionAction" ) )
                {
                    BuildPositionAction bsp = new BuildPositionAction();
                    bsp.BuildFromAction( ( PositionAction ) action );

                    if ( bsp.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = bsp.Action;
                    }
                }

                else if ( action.GetType().ToString().Contains( "ConditionalVelocityAction" ) )
                {
                    ConditionalActionBuilder velocityAction = new ConditionalActionBuilder();
                    velocityAction.BuildFromAction( ( ConditionalVelocityAction ) action );

                    if ( velocityAction.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = velocityAction.Action;
                    }
                }

                else if ( action.GetType().ToString().Contains( "VelocityAction" ) )
                {
                    BuildVelocityAction velocityAction = new BuildVelocityAction();
                    velocityAction.BuildFromAction( ( VelocityAction ) action );

                    if ( velocityAction.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = velocityAction.Action;
                    }
                }

                else if ( action.GetType().ToString().Contains( "AndAction" ) )
                {
                    BuildAndGesture andAction = new BuildAndGesture();
                    andAction.BuildFromAction( ( AndAction ) action );

                    if ( andAction.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = andAction.Action;
                    }
                }

                else if ( action.GetType().ToString().Contains( "OrAction" ) )
                {
                    BuildOrGesture orAction = new BuildOrGesture();
                    orAction.BuildFromAction( ( OrAction ) action );

                    if ( orAction.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = orAction.Action;
                    }
                }

                else if ( action.GetType().ToString().Contains( "TimeAction" ) )
                {
                    BuildTimeAction timeAction = new BuildTimeAction();
                    timeAction.BuildFromAction( ( TimeAction ) action );

                    if ( timeAction.ShowDialog() == DialogResult.OK )
                    {
                        updatedAction = timeAction.Action;
                    }
                }

                if ( updatedAction != null )
                {
                    currentGesture.ReplaceAction( action, updatedAction );
                    RebuildActionList();
                }                
            }
            else
            {
                MessageBox.Show( "Select an action to edit" );
            }
        }

        private void BuildTreeFromList()
        {
            TVGesturesSkel1.Nodes[0].Nodes[0].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[1].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[2].Nodes.Clear();
            TVGesturesSkel1.Nodes[0].Nodes[3].Nodes.Clear();

            foreach ( Skeliton skel in _Skelitons )
            {
                foreach ( Gesture gesture in skel.GestureList )
                {
                    AddNodeToTree( skel.ID, gesture.GestureName );
                }
            }            
        }

        private void Import( string fileName )
        {
            StreamReader streamReader = null;
            string line = string.Empty;

            try
            {
                streamReader = new StreamReader( fileName );
                

                Gesture buildingGesture = null;
                int skelID = 0;

                while( ( line = streamReader.ReadLine() ) != null )
                {
                    if ( line == "--------------------------------------------------------Skeliton-----------------------------------------------------" )
                    {
                        skelID = int.Parse( streamReader.ReadLine().Substring( 3 ) );
                    }

                    else if ( line == "-----------------Gesture------------------" )
                    {
                        line = streamReader.ReadLine();//read GestureName:
                        buildingGesture = new Gesture( line.Substring( 12 ) );
                    }

                    else if ( line == "-----Action-----" )
                    {
                        buildingGesture.AddAction( LoadAction( streamReader ) );
                    }

                    else if ( line == "-----------------End------------------" )
                    {
                        _Skelitons[skelID].GestureList.Add( buildingGesture );
                    }
                }

                BuildTreeFromList();                            
            }
            catch ( Exception e )
            {
                MessageBox.Show( e.Message );
            }
            finally
            {
                if ( streamReader != null )
                {
                    streamReader.Close();
                }
            }
        }

        private Action LoadAction( StreamReader streamReader )
        {
            Action action = null; 

            string line = streamReader.ReadLine();//read ActionType:
            string type = line.Substring( 11 );

            if ( type == "Position" )
            {
                PositionAction posAction = new PositionAction();
                posAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                posAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:
                posAction.FirstBodyPart = int.Parse( streamReader.ReadLine().Substring( 4 ) );//read FBP:
                posAction.Relationship = int.Parse( streamReader.ReadLine().Substring( 9 ) );//read Relationship:
                posAction.SecondBodyPart = int.Parse( streamReader.ReadLine().Substring( 4 ) );//read SBP:
                posAction.UpperBoundsRelationshipValue = float.Parse( streamReader.ReadLine().Substring( 17 ) );//read UpperBoundsValue:
                posAction.LowerBoundsRelationshipValue = float.Parse( streamReader.ReadLine().Substring( 17 ) );//read LowerBoundsValue:

                action = posAction;
            }

            else if ( type == "Velocity" )
            {
                VelocityAction velAction = new VelocityAction();
                velAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                velAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:
                velAction.FirstBodyPart = int.Parse( streamReader.ReadLine().Substring( 4 ) );//read FBP:
                velAction.Relationship = int.Parse( streamReader.ReadLine().Substring( 9 ) );//read Relationship:                            
                velAction.RelationshipValue = float.Parse( streamReader.ReadLine().Substring( 6 ) );//read RelationshipL:

                action = velAction;
            }

            else if ( type == "ConditionalVelocity" )
            {
                ConditionalVelocityAction velAction = new ConditionalVelocityAction();
                velAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                velAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:
                velAction.FirstBodyPart = int.Parse( streamReader.ReadLine().Substring( 4 ) );//read FBP:
                velAction.VelocityRelationship = int.Parse( streamReader.ReadLine().Substring( 17 ) );//read VelocityRelation:
                velAction.ConditionalBodyPart = int.Parse( streamReader.ReadLine().Substring( 12 ) );//read ConditionBP:   
                velAction.ConditionRelationship = int.Parse( streamReader.ReadLine().Substring( 24 ) );//read ConditionalRelationship:
                velAction.RelationshipValue = float.Parse( streamReader.ReadLine().Substring( 14 ) );//read VelocityValue:

                if ( streamReader.ReadLine() == "-----InnerAction-----" )
                {
                    velAction.PassAction = ( AndAction ) LoadAction( streamReader );
                }

                action = velAction;
            }

            else if ( type == "And" )
            {
                AndAction andAction = new AndAction();
                andAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                andAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:

                while ( true )
                {
                    line = streamReader.ReadLine();
                    if ( line == "-----MultiEnd-----" )
                    {
                        break;
                    }
                    else if ( line == "-----InnerAction-----" )
                    {
                        andAction.AddAction( LoadAction( streamReader ) );
                    }
                }

                action = andAction;
            }

            else if ( type == "Or" )
            {
                OrAction andAction = new OrAction();
                andAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                andAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:

                while ( true )
                {
                    line = streamReader.ReadLine();
                    if ( line == "-----MultiEnd-----" )
                    {
                        break;
                    }
                    else if ( line == "-----InnerAction-----" )
                    {
                        andAction.AddAction( LoadAction( streamReader ) );
                    }
                }

                action = andAction;
            }

            else if ( type == "Time" )
            {
                TimeAction timeAction = new TimeAction();
                timeAction.Name = streamReader.ReadLine().Substring( 11 );//read name:
                timeAction.Timeout = float.Parse( streamReader.ReadLine().Substring( 8 ) );//read FBP:
                timeAction.TimeToPass = float.Parse( streamReader.ReadLine().Substring( 11 ) );//read TimeToPass

                action = timeAction;
            }

            return action;
        }

        private void importToolStripMenuItem_Click( object sender, EventArgs e )
        {
            OpenFileDialog openFileDio = new OpenFileDialog();
            openFileDio.Filter = "txt files (*.txt)|*.txt";

            if ( openFileDio.ShowDialog() == System.Windows.Forms.DialogResult.OK )
            {
                Import( openFileDio.FileName );
            }
        }

        private void BUp_Click( object sender, EventArgs e )
        {
            if ( LBActions.SelectedItem != null )
            {
                if ( LBActions.SelectedIndex != 0 )
                {
                    string listBoxItem = LBActions.SelectedItem.ToString();
                    int currentIndex = LBActions.SelectedIndex;
                    LBActions.Items.Remove( listBoxItem );
                    LBActions.Items.Insert( currentIndex - 1, listBoxItem );
                    LBActions.SelectedIndex = currentIndex - 1;

                    Gesture gestureToChange = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );

                    Action action = gestureToChange.GetAction( LBActions.SelectedItem.ToString() );
                    gestureToChange.RemoveAction( LBActions.SelectedItem.ToString() );
                    gestureToChange.AddActionAt( currentIndex - 1, action );
                }
            }
            else
            {
                MessageBox.Show( "Please select an item" );

            }
        }

        private void BDown_Click( object sender, EventArgs e )
        {
            if ( LBActions.SelectedItem != null )
            {
                if ( LBActions.SelectedIndex != LBActions.Items.Count - 1 )
                {
                    string listBoxItem = LBActions.SelectedItem.ToString();
                    int currentIndex = LBActions.SelectedIndex;
                    LBActions.Items.Remove( listBoxItem );
                    LBActions.Items.Insert( currentIndex + 1, listBoxItem );
                    LBActions.SelectedIndex = currentIndex + 1;

                    Gesture gestureToChange = GetGesture( GetSelectedNodeSkeliton(), TVGesturesSkel1.SelectedNode.Text );

                    Action action = gestureToChange.GetAction( LBActions.SelectedItem.ToString() );
                    gestureToChange.RemoveAction( LBActions.SelectedItem.ToString() );
                    gestureToChange.AddActionAt( currentIndex + 1, action );
                }
            }
            else
            {
                MessageBox.Show( "Please select an item" );

            }
        }

        private void aboutToolStripMenuItem_Click( object sender, EventArgs e )
        {
            HelpWindow help = new HelpWindow();
            help.ShowDialog();
        }
    }
}
