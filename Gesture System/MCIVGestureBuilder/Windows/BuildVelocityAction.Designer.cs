namespace MCIVGestureBuilder
{
    partial class BuildVelocityAction
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
            this.BCancel = new System.Windows.Forms.Button();
            this.BBuild = new System.Windows.Forms.Button();
            this.TBVal = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.CBRel = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.CBFirst = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.TBName = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.TBTimout = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BCancel
            // 
            this.BCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.BCancel.Location = new System.Drawing.Point(317, 224);
            this.BCancel.Name = "BCancel";
            this.BCancel.Size = new System.Drawing.Size(75, 23);
            this.BCancel.TabIndex = 53;
            this.BCancel.Text = "Cancel";
            this.BCancel.UseVisualStyleBackColor = true;
            // 
            // BBuild
            // 
            this.BBuild.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.BBuild.Location = new System.Drawing.Point(236, 224);
            this.BBuild.Name = "BBuild";
            this.BBuild.Size = new System.Drawing.Size(75, 23);
            this.BBuild.TabIndex = 52;
            this.BBuild.Text = "OK";
            this.BBuild.UseVisualStyleBackColor = true;
            this.BBuild.Click += new System.EventHandler(this.BBuild_Click);
            // 
            // TBVal
            // 
            this.TBVal.Location = new System.Drawing.Point(120, 181);
            this.TBVal.Name = "TBVal";
            this.TBVal.Size = new System.Drawing.Size(196, 20);
            this.TBVal.TabIndex = 51;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 184);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(95, 13);
            this.label3.TabIndex = 50;
            this.label3.Text = "Relationship Value";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(19, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(181, 24);
            this.label1.TabIndex = 47;
            this.label1.Text = "Build Veloctiy Action";
            // 
            // CBRel
            // 
            this.CBRel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CBRel.FormattingEnabled = true;
            this.CBRel.Items.AddRange(new object[] {
            "GREATER_THAN",
            "LESS_THAN"});
            this.CBRel.Location = new System.Drawing.Point(119, 154);
            this.CBRel.Name = "CBRel";
            this.CBRel.Size = new System.Drawing.Size(197, 21);
            this.CBRel.TabIndex = 46;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 162);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(65, 13);
            this.label10.TabIndex = 45;
            this.label10.Text = "Relationship";
            // 
            // CBFirst
            // 
            this.CBFirst.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CBFirst.FormattingEnabled = true;
            this.CBFirst.Items.AddRange(new object[] {
            "Head",
            "Neck",
            "Torso",
            "Waist",
            "LeftCollar",
            "LeftShoulder",
            "LeftElboy",
            "LeftWrist",
            "LeftHand",
            "LeftFingureTip",
            "RightCollar",
            "RightShoulder",
            "RightElboy",
            "RightWrist",
            "RightHand",
            "RightFingureTip",
            "LeftHip",
            "LeftKnee",
            "LeftAnkle",
            "LeftFoot",
            "RighttHip",
            "RightKnee",
            "RightAnkl",
            "RightFoot"});
            this.CBFirst.Location = new System.Drawing.Point(119, 127);
            this.CBFirst.Name = "CBFirst";
            this.CBFirst.Size = new System.Drawing.Size(196, 21);
            this.CBFirst.TabIndex = 44;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(18, 135);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(69, 13);
            this.label9.TabIndex = 43;
            this.label9.Text = "FirstBodyPart";
            // 
            // TBName
            // 
            this.TBName.Location = new System.Drawing.Point(120, 64);
            this.TBName.Name = "TBName";
            this.TBName.Size = new System.Drawing.Size(197, 20);
            this.TBName.TabIndex = 42;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(20, 67);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(68, 13);
            this.label7.TabIndex = 41;
            this.label7.Text = "Action Name";
            // 
            // TBTimout
            // 
            this.TBTimout.Location = new System.Drawing.Point(120, 90);
            this.TBTimout.Name = "TBTimout";
            this.TBTimout.Size = new System.Drawing.Size(197, 20);
            this.TBTimout.TabIndex = 43;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(18, 93);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(45, 13);
            this.label4.TabIndex = 54;
            this.label4.Text = "Timeout";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(323, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 55;
            this.label2.Text = "seconds";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(322, 184);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 56;
            this.label5.Text = "VUnits";
            // 
            // BuildVelocityAction
            // 
            this.AcceptButton = this.BBuild;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(411, 259);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.TBTimout);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.BCancel);
            this.Controls.Add(this.BBuild);
            this.Controls.Add(this.TBVal);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CBRel);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.CBFirst);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.TBName);
            this.Controls.Add(this.label7);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "BuildVelocityAction";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "BuildVelocityAction";
            this.Load += new System.EventHandler(this.BuildVelocityAction_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BCancel;
        private System.Windows.Forms.Button BBuild;
        private System.Windows.Forms.TextBox TBVal;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox CBRel;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox CBFirst;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox TBName;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox TBTimout;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;

    }
}