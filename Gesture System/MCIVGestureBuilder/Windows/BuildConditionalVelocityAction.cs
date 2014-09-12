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
    public partial class ConditionalActionBuilder : Form
    {
        public ConditionalVelocityAction Action = new ConditionalVelocityAction();

        public ConditionalActionBuilder()
        {
            InitializeComponent();

            CBFirst.SelectedIndex = 0;
            CBSecond.SelectedIndex = 0;
            CBRel.SelectedIndex = 0;
            CBCRel.SelectedIndex = 0;
        }

        private void BBuild_Click( object sender, EventArgs e )
        {
            Action.Name = TBName.Text;
            Action.FirstBodyPart = Logic.StringsToInt( CBFirst.Text );
            Action.VelocityRelationship = Logic.StringsToInt( CBRel.Text );
            Action.ConditionRelationship = Logic.StringsToInt( CBCRel.Text );
            Action.ConditionalBodyPart = Logic.StringsToInt( CBSecond.Text );

            if ( TBActionEndPoint.Text.Length == 0 )
            {
                MessageBox.Show( "Action Requires an End Action" );
                return;
            }
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

            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void ConditionalActionBuilder_Load( object sender, EventArgs e )
        {

        }

        private void button1_Click( object sender, EventArgs e )
        {
            BuildAndGesture CAB = new BuildAndGesture();

            if ( CAB.ShowDialog() == DialogResult.OK )
            {
                Action.PassAction = CAB.Action;
                TBActionEndPoint.Text = Action.PassAction.Name;
                BEdit.Enabled = true;
            }
        }

        private void BEdit_Click( object sender, EventArgs e )
        {
            BuildAndGesture CAB = new BuildAndGesture();
            CAB.BuildFromAction( Action.PassAction );

            if ( CAB.ShowDialog() == DialogResult.OK )
            {
                Action.PassAction = CAB.Action;
                TBActionEndPoint.Text = Action.PassAction.Name;
                BEdit.Enabled = true;
            }
        }

        public void BuildFromAction( ConditionalVelocityAction cva )
        {
            Action = cva;

            TBName.Text = Action.Name;
            TBTimout.Text = Action.Timeout.ToString();
            CBFirst.SelectedItem = Logic.IntToString( Action.FirstBodyPart );
            CBRel.SelectedItem = Logic.IntToString( Action.VelocityRelationship );
            CBSecond.SelectedItem = Logic.IntToString( Action.ConditionalBodyPart );
            CBCRel.SelectedItem = Logic.IntToString( Action.ConditionRelationship );
            TBVal.Text = Action.RelationshipValue.ToString();
            TBActionEndPoint.Text = Action.PassAction.Name;

            BEdit.Enabled = true;
        }
    }
}
