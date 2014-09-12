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
    public partial class BuildTimeAction : Form
    {
        public TimeAction Action { get; private set; }

        public BuildTimeAction()
        {
            InitializeComponent();
        }

        private void BCancel_Click( object sender, EventArgs e )
        {
            this.Close();
        }

        private void BBuild_Click( object sender, EventArgs e )
        {
            Action = new TimeAction();
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

            try
            {
                Action.TimeToPass = float.Parse( TBTimeToPass.Text );
            }
            catch ( System.Exception ex )
            {
                MessageBox.Show( "Time Period value must be a float" );
                return;
            }

            DialogResult = System.Windows.Forms.DialogResult.OK;
            this.Close();
        }

        public void BuildFromAction( TimeAction pastAction )
        {
            TBName.Text = pastAction.Name;
            TBTimout.Text = pastAction.Timeout.ToString();
            TBTimeToPass.Text = pastAction.TimeToPass.ToString();
        }
    }
}
