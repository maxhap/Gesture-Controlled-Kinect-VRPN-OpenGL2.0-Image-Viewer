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
    public partial class Input : Form
    {
        public Input()
        {
            InitializeComponent();
        }

        private void Input_Load( object sender, EventArgs e )
        {
            MinimizeBox = false;
            MaximizeBox = false;
        }

        public String GestureText
        {
            get { return textBox1.Text; }
        }

        private void BOK_Click( object sender, EventArgs e )
        {
            this.Visible = false;
        }

        private void BCancel_Click( object sender, EventArgs e )
        {
            this.Visible = false;   
        }
    }
}
