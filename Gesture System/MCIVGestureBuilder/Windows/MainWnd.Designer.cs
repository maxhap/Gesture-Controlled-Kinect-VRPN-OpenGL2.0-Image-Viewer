namespace MCIVGestureBuilder
{
    partial class MainWnd
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.TVGesturesSkel1 = new System.Windows.Forms.TreeView();
            this.panel2 = new System.Windows.Forms.Panel();
            this.BDown = new System.Windows.Forms.Button();
            this.BUp = new System.Windows.Forms.Button();
            this.BEdit = new System.Windows.Forms.Button();
            this.BBuild = new System.Windows.Forms.Button();
            this.CBActionType = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.BActionDelete = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.LBActions = new System.Windows.Forms.ListBox();
            this.TBGName = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteActionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteAllGesturesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label7 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.White;
            this.panel1.Controls.Add(this.splitContainer1);
            this.panel1.Location = new System.Drawing.Point(12, 85);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1264, 565);
            this.panel1.TabIndex = 0;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.TVGesturesSkel1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.label2);
            this.splitContainer1.Panel2.Controls.Add(this.label9);
            this.splitContainer1.Panel2.Controls.Add(this.label7);
            this.splitContainer1.Panel2.Controls.Add(this.panel2);
            this.splitContainer1.Size = new System.Drawing.Size(1264, 565);
            this.splitContainer1.SplitterDistance = 200;
            this.splitContainer1.TabIndex = 0;
            this.splitContainer1.SplitterMoved += new System.Windows.Forms.SplitterEventHandler(this.splitContainer1_SplitterMoved);
            // 
            // TVGesturesSkel1
            // 
            this.TVGesturesSkel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.TVGesturesSkel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TVGesturesSkel1.Location = new System.Drawing.Point(0, 0);
            this.TVGesturesSkel1.Name = "TVGesturesSkel1";
            this.TVGesturesSkel1.Size = new System.Drawing.Size(200, 565);
            this.TVGesturesSkel1.TabIndex = 0;
            this.TVGesturesSkel1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.TVGestures_AfterSelect);
            this.TVGesturesSkel1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.TVGestures_MouseClick);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.BDown);
            this.panel2.Controls.Add(this.BUp);
            this.panel2.Controls.Add(this.BEdit);
            this.panel2.Controls.Add(this.BBuild);
            this.panel2.Controls.Add(this.CBActionType);
            this.panel2.Controls.Add(this.label8);
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.label5);
            this.panel2.Controls.Add(this.BActionDelete);
            this.panel2.Controls.Add(this.label4);
            this.panel2.Controls.Add(this.LBActions);
            this.panel2.Controls.Add(this.TBGName);
            this.panel2.Controls.Add(this.label3);
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1060, 565);
            this.panel2.TabIndex = 0;
            this.panel2.Visible = false;
            // 
            // BDown
            // 
            this.BDown.Location = new System.Drawing.Point(304, 357);
            this.BDown.Name = "BDown";
            this.BDown.Size = new System.Drawing.Size(75, 23);
            this.BDown.TabIndex = 26;
            this.BDown.Text = "Down";
            this.BDown.UseVisualStyleBackColor = true;
            this.BDown.Click += new System.EventHandler(this.BDown_Click);
            // 
            // BUp
            // 
            this.BUp.Location = new System.Drawing.Point(304, 328);
            this.BUp.Name = "BUp";
            this.BUp.Size = new System.Drawing.Size(75, 23);
            this.BUp.TabIndex = 25;
            this.BUp.Text = "Up";
            this.BUp.UseVisualStyleBackColor = true;
            this.BUp.Click += new System.EventHandler(this.BUp_Click);
            // 
            // BEdit
            // 
            this.BEdit.Location = new System.Drawing.Point(142, 530);
            this.BEdit.Name = "BEdit";
            this.BEdit.Size = new System.Drawing.Size(75, 23);
            this.BEdit.TabIndex = 24;
            this.BEdit.Text = "Edit";
            this.BEdit.UseVisualStyleBackColor = true;
            this.BEdit.Click += new System.EventHandler(this.BEdit_Click);
            // 
            // BBuild
            // 
            this.BBuild.Location = new System.Drawing.Point(677, 159);
            this.BBuild.Name = "BBuild";
            this.BBuild.Size = new System.Drawing.Size(75, 23);
            this.BBuild.TabIndex = 23;
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
            "Conditional Velocity",
            "And",
            "Or",
            "TimeToPass"});
            this.CBActionType.Location = new System.Drawing.Point(555, 132);
            this.CBActionType.Name = "CBActionType";
            this.CBActionType.Size = new System.Drawing.Size(197, 21);
            this.CBActionType.TabIndex = 22;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(481, 135);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(64, 13);
            this.label8.TabIndex = 21;
            this.label8.Text = "Action Type";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(40, 96);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(83, 20);
            this.label6.TabIndex = 20;
            this.label6.Text = "Action List";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(480, 96);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 20);
            this.label5.TabIndex = 19;
            this.label5.Text = "Build an Action";
            // 
            // BActionDelete
            // 
            this.BActionDelete.Location = new System.Drawing.Point(223, 530);
            this.BActionDelete.Name = "BActionDelete";
            this.BActionDelete.Size = new System.Drawing.Size(75, 23);
            this.BActionDelete.TabIndex = 18;
            this.BActionDelete.Text = "Delete";
            this.BActionDelete.UseVisualStyleBackColor = true;
            this.BActionDelete.Click += new System.EventHandler(this.BActionDelete_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(41, 179);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(42, 13);
            this.label4.TabIndex = 17;
            this.label4.Text = "Actions";
            // 
            // LBActions
            // 
            this.LBActions.FormattingEnabled = true;
            this.LBActions.Location = new System.Drawing.Point(44, 195);
            this.LBActions.Name = "LBActions";
            this.LBActions.Size = new System.Drawing.Size(254, 329);
            this.LBActions.TabIndex = 16;
            // 
            // TBGName
            // 
            this.TBGName.Enabled = false;
            this.TBGName.Location = new System.Drawing.Point(122, 133);
            this.TBGName.Name = "TBGName";
            this.TBGName.Size = new System.Drawing.Size(176, 20);
            this.TBGName.TabIndex = 15;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(41, 136);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 13);
            this.label3.TabIndex = 14;
            this.label3.Text = "Gesture Name";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(330, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(599, 37);
            this.label1.TabIndex = 1;
            this.label1.Text = "Media City Image Viewer Gesture Builder";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1288, 24);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importToolStripMenuItem,
            this.exportToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // importToolStripMenuItem
            // 
            this.importToolStripMenuItem.Name = "importToolStripMenuItem";
            this.importToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.importToolStripMenuItem.Text = "Import";
            this.importToolStripMenuItem.Click += new System.EventHandler(this.importToolStripMenuItem_Click);
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.exportToolStripMenuItem.Text = "Export";
            this.exportToolStripMenuItem.Click += new System.EventHandler(this.exportToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.deleteActionsToolStripMenuItem,
            this.deleteAllGesturesToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // deleteActionsToolStripMenuItem
            // 
            this.deleteActionsToolStripMenuItem.Name = "deleteActionsToolStripMenuItem";
            this.deleteActionsToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.deleteActionsToolStripMenuItem.Text = "Delete All Actions";
            this.deleteActionsToolStripMenuItem.Click += new System.EventHandler(this.deleteActionsToolStripMenuItem_Click);
            // 
            // deleteAllGesturesToolStripMenuItem
            // 
            this.deleteAllGesturesToolStripMenuItem.Name = "deleteAllGesturesToolStripMenuItem";
            this.deleteAllGesturesToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.deleteAllGesturesToolStripMenuItem.Text = "Delete All Gestures";
            this.deleteAllGesturesToolStripMenuItem.Click += new System.EventHandler(this.deleteAllGesturesToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(99, 22);
            this.aboutToolStripMenuItem.Text = "Help";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(41, 62);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(536, 18);
            this.label7.TabIndex = 1;
            this.label7.Text = "To create a new gesture right click the desired skeliton and select \"New Gesture\"" +
    "";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(40, 33);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(148, 20);
            this.label9.TabIndex = 14;
            this.label9.Text = "Create a Gesture";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(42, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(722, 18);
            this.label2.TabIndex = 15;
            this.label2.Text = "To create an action for this drop down select your desired type from the drop dow" +
    "n and press the build button";
            this.label2.Visible = false;
            // 
            // MainWnd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(1288, 662);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainWnd";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Media City Image Viewer";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.TreeView TVGesturesSkel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button BBuild;
        private System.Windows.Forms.ComboBox CBActionType;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button BActionDelete;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox LBActions;
        private System.Windows.Forms.TextBox TBGName;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ToolStripMenuItem importToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteActionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteAllGesturesToolStripMenuItem;
        private System.Windows.Forms.Button BEdit;
        private System.Windows.Forms.Button BDown;
        private System.Windows.Forms.Button BUp;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label2;
    }
}

