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
    public partial class BuildPositionAction : Form
    {
        public PositionAction Action { get; private set; }

        public BuildPositionAction()
        {
            InitializeComponent();
            CBFirst.SelectedIndex = 0;
            CBRel.SelectedIndex = 0;
            CBSecond.SelectedIndex = 0;
        }

        private void BBuild_Click( object sender, EventArgs e )
        {
            Action = new PositionAction();
            Action.Name = TBName.Text;
            Action.FirstBodyPart = Logic.StringsToInt( CBFirst.Text );
            Action.Relationship = Logic.StringsToInt( CBRel.Text );
            Action.SecondBodyPart = Logic.StringsToInt( CBSecond.Text );
            
            try
            {
                Action.Timeout = float.Parse( TBTimout.Text );
            }
            catch (System.Exception ex)
            {
                MessageBox.Show( "Timeout value must be a float" );
                return;
            }

            try
            {
                Action.UpperBoundsRelationshipValue = float.Parse( TBVal.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Upper value value must be a float" );
                
                return;
            }

            try
            {
                Action.LowerBoundsRelationshipValue = float.Parse( TBLVal.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Lower value value must be a float" );

                return;
            }

            if ( TBName.Text.Trim() == "" )
            {
                MessageBox.Show( "Action name must not be empty" );
                return;
            }

            DialogResult = System.Windows.Forms.DialogResult.OK;
            this.Close();
        }

        private void BuildPositionAction_Load( object sender, EventArgs e )
        {
            MaximizeBox = false;
            MinimizeBox = false;
        }

        public void BuildFromAction( PositionAction pastAction )
        {
            TBName.Text = pastAction.Name;
            TBTimout.Text = pastAction.Timeout.ToString();

            CBFirst.SelectedItem = Logic.IntToString( pastAction.FirstBodyPart );
            CBSecond.SelectedItem = Logic.IntToString( pastAction.SecondBodyPart );
            CBRel.SelectedItem = Logic.IntToString( pastAction.Relationship );
            TBVal.Text = pastAction.UpperBoundsRelationshipValue.ToString();
            TBLVal.Text = pastAction.LowerBoundsRelationshipValue.ToString();
        }
    }
}
