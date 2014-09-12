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
    public partial class BuildVelocityAction : Form
    {
        public VelocityAction Action { get; private set; }

        public BuildVelocityAction()
        {
            InitializeComponent();
            CBFirst.SelectedIndex = 0;
            CBRel.SelectedIndex = 0;            

            MaximizeBox = false;
            MinimizeBox = false;
        }

        private void BuildVelocityAction_Load( object sender, EventArgs e )
        {

        }

        private void BBuild_Click( object sender, EventArgs e )
        {
            Action = new VelocityAction();
            Action.Name = TBName.Text;            
            Action.FirstBodyPart = Logic.StringsToInt( CBFirst.Text );
            Action.Relationship = Logic.StringsToInt( CBRel.Text );

            try
            {
                Action.Timeout = float.Parse( TBTimout.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Timeout value must be a float" );
                return;
            }

            try
            {
                Action.RelationshipValue = float.Parse( TBVal.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Relationship value must be an float" );

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

        public void BuildFromAction( VelocityAction pastAction )
        {
            TBName.Text = pastAction.Name;
            TBTimout.Text = pastAction.Timeout.ToString();
            CBFirst.SelectedItem = Logic.IntToString( pastAction.FirstBodyPart );            
            CBRel.SelectedItem = Logic.IntToString( pastAction.Relationship );
            TBVal.Text = pastAction.RelationshipValue.ToString();
        }
    }
}
