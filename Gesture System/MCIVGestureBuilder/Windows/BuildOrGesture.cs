using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MCIVGestureBuilder
{
    public partial class BuildOrGesture : Form
    {
        public OrAction Action { get; private set; }

        public BuildOrGesture()
        {
            InitializeComponent();
            CBActionType.SelectedIndex = 0;
        }

        private void BBuild_Click( object sender, EventArgs e )
        {
            if ( CBActionType.SelectedIndex == 0 )
            {
                BuildPositionAction bsp = new BuildPositionAction();

                if ( bsp.ShowDialog() == DialogResult.OK )
                {
                    AddAction( bsp.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 1 )
            {
                BuildVelocityAction velocityAction = new BuildVelocityAction();

                if ( velocityAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( velocityAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 2 )
            {
                BuildAndGesture andAction = new BuildAndGesture();

                if ( andAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( andAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 3 )
            {
                BuildOrGesture orAction = new BuildOrGesture();

                if ( orAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( orAction.Action );
                }
            }

            else if ( CBActionType.SelectedIndex == 4 )
            {
                BuildTimeAction timeAction = new BuildTimeAction();

                if ( timeAction.ShowDialog() == DialogResult.OK )
                {
                    AddAction( timeAction.Action );
                }
            }
        }

        private void AddAction( Action action )
        {
            if ( Action == null )
            {
                Action = new OrAction();
            }

            if ( !LBAction.Items.Contains( action.Name ) )
            {
                this.Action.AddAction( action );
                RebuildActionList();
            }
            else
            {
                MessageBox.Show( "Sorry '" + action.Name + "' is already asigned to another action" );
                return;
            }
        }

        public void RebuildActionList()
        {
            LBAction.Items.Clear();

            foreach ( Action action in Action.GetActions() )
            {
                LBAction.Items.Add( action.Name );
            }
        }

        private void BOK_Click( object sender, EventArgs e )
        {
            if ( TBName.Text.Length == 0 )
            {
                MessageBox.Show( "Please assign the action a name" );
                return;
            }

            if ( LBAction.Items.Count < 2 )
            {
                MessageBox.Show( "And action requires at least two actions" );
                return;
            }

            Action.Name = TBName.Text;
            
            try
            {
                Action.Timeout = float.Parse( TBTimout.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Timeout value must be a float" );
                return;
            }
            
            DialogResult = System.Windows.Forms.DialogResult.OK;
            this.Close();
        }        

        private void BDelete_Click( object sender, EventArgs e )
        {
            if ( LBAction.SelectedItem == null )
            {
                MessageBox.Show( "Please select an item" );
                return;
            }

            Action.RemoveAction( LBAction.SelectedItem.ToString() );
            LBAction.Items.RemoveAt( LBAction.SelectedIndex );
        }

        public void BuildFromAction( OrAction pastAction )
        {
            Action = pastAction;
            TBName.Text = pastAction.Name;
            TBTimout.Text = pastAction.Timeout.ToString();

            RebuildActionList();
        }

        private void BEdit_Click( object sender, EventArgs e )
        {
            if ( LBAction.SelectedItem != null )
            {
                Action action = Action.GetAction( LBAction.SelectedItem.ToString() );

                try
                {
                    Action.Timeout = float.Parse( TBTimout.Text );
                }
                catch ( System.Exception ex )
                {
                    MessageBox.Show( "Timeout value must be a float" );
                    return;
                }

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

                else if ( action.GetType().ToString().Contains( "VeloctiyAction" ) )
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
                    Action.ReplaceAction( action, updatedAction );
                    RebuildActionList();
                }
            }
            else
            {
                MessageBox.Show( "Select an action to edit" );
            }
        }

        private void BuildOrGesture_Load( object sender, EventArgs e )
        {

        }
    }
}
