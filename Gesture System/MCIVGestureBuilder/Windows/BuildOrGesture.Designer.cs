namespace MCIVGestureBuilder
{
    partial class BuildOrGesture
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose( bool disposing )
        {
            if ( disposing && ( components != null ) )
            {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.TBName = new System.Windows.Forms.TextBox();
            this.labelName = new System.Windows.Forms.Label();
            this.BOK = new System.Windows.Forms.Button();
            this.BCancel = new System.Windows.Forms.Button();
            this.BBuild = new System.Windows.Forms.Button();
            this.CBActionType = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.BDelete = new System.Windows.Forms.Button();
            this.LBAction = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.BEdit = new System.Windows.Forms.Button();
            this.TBTimout = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // TBName
            // 
            this.TBName.Location = new System.Drawing.Point(59, 49);
            this.TBName.Name = "TBName";
            this.TBName.Size = new System.Drawing.Size(197, 20);
            this.TBName.TabIndex = 42;
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Location = new System.Drawing.Point(8, 52);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(35, 13);
            this.labelName.TabIndex = 41;
            this.labelName.Text = "Name";
            // 
            // BOK
            // 
            this.BOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BOK.Location = new System.Drawing.Point(461, 290);
            this.BOK.Name = "BOK";
            this.BOK.Size = new System.Drawing.Size(75, 23);
            this.BOK.TabIndex = 50;
            this.BOK.Text = "OK";
            this.BOK.UseVisualStyleBackColor = true;
            this.BOK.Click += new System.EventHandler(this.BOK_Click);
            // 
            // BCancel
            // 
            this.BCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.BCancel.Location = new System.Drawing.Point(542, 290);
            this.BCancel.Name = "BCancel";
            this.BCancel.Size = new System.Drawing.Size(75, 23);
            this.BCancel.TabIndex = 49;
            this.BCancel.Text = "Cancel";
            this.BCancel.UseVisualStyleBackColor = true;
            // 
            // BBuild
            // 
            this.BBuild.Location = new System.Drawing.Point(541, 162);
            this.BBuild.Name = "BBuild";
            this.BBuild.Size = new System.Drawing.Size(75, 23);
            this.BBuild.TabIndex = 45;
            this.BBuild.Text = "Build";
            this.BBuild.UseVisualStyleBackColor = true;
            this.BBuild.Click += new System.EventHandler(this.BBuild_Click);
            // 
            // CBActionType
            // 
            this.CBActionType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CBActionType.FormattingEnabled = true;
            this.CBActionType.Items.AddRange(new object[] {
            "Position",
            "Velocity",
            "And",
            "Or",
            "TimeToPass"});
            this.CBActionType.Location = new System.Drawing.Point(419, 135);
            this.CBActionType.Name = "CBActionType";
            this.CBActionType.Size = new System.Drawing.Size(197, 21);
            this.CBActionType.TabIndex = 44;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(345, 138);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(64, 13);
            this.label8.TabIndex = 36;
            this.label8.Text = "Action Type";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(344, 99);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 20);
            this.label5.TabIndex = 35;
            this.label5.Text = "Build an Action";
            // 
            // BDelete
            // 
            this.BDelete.Location = new System.Drawing.Point(197, 266);
            this.BDelete.Name = "BDelete";
            this.BDelete.Size = new System.Drawing.Size(75, 23);
            this.BDelete.TabIndex = 48;
            this.BDelete.Text = "Delete";
            this.BDelete.UseVisualStyleBackColor = true;
            this.BDelete.Click += new System.EventHandler(this.BDelete_Click);
            // 
            // LBAction
            // 
            this.LBAction.FormattingEnabled = true;
            this.LBAction.Location = new System.Drawing.Point(11, 113);
            this.LBAction.Name = "LBAction";
            this.LBAction.Size = new System.Drawing.Size(261, 147);
            this.LBAction.TabIndex = 46;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(7, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(114, 20);
            this.label1.TabIndex = 32;
            this.label1.Text = "Build Or Action";
            // 
            // BEdit
            // 
            this.BEdit.Location = new System.Drawing.Point(116, 266);
            this.BEdit.Name = "BEdit";
            this.BEdit.Size = new System.Drawing.Size(75, 23);
            this.BEdit.TabIndex = 47;
            this.BEdit.Text = "Edit";
            this.BEdit.UseVisualStyleBackColor = true;
            this.BEdit.Click += new System.EventHandler(this.BEdit_Click);
            // 
            // TBTimout
            // 
            this.TBTimout.Location = new System.Drawing.Point(59, 75);
            this.TBTimout.Name = "TBTimout";
            this.TBTimout.Size = new System.Drawing.Size(197, 20);
            this.TBTimout.TabIndex = 43;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 78);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(45, 13);
            this.label4.TabIndex = 45;
            this.label4.Text = "Timeout";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(262, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 51;
            this.label2.Text = "seconds";
            // 
            // BuildOrGesture
            // 
            this.AcceptButton = this.BBuild;
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(624, 319);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.TBTimout);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.BEdit);
            this.Controls.Add(this.TBName);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.BOK);
            this.Controls.Add(this.BCancel);
            this.Controls.Add(this.BBuild);
            this.Controls.Add(this.CBActionType);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.BDelete);
            this.Controls.Add(this.LBAction);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "BuildOrGesture";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "BuildOrGesture";
            this.Load += new System.EventHandler(this.BuildOrGesture_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TBName;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Button BOK;
        private System.Windows.Forms.Button BCancel;
        private System.Windows.Forms.Button BBuild;
        private System.Windows.Forms.ComboBox CBActionType;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button BDelete;
        private System.Windows.Forms.ListBox LBAction;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button BEdit;
        private System.Windows.Forms.TextBox TBTimout;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
    }
}