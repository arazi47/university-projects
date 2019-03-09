namespace DBMSLab1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.fillDgvButton = new System.Windows.Forms.Button();
            this.parentTableDgv = new System.Windows.Forms.DataGridView();
            this.childTableDgv = new System.Windows.Forms.DataGridView();
            this.addPlayerButton = new System.Windows.Forms.Button();
            this.idTextBox = new System.Windows.Forms.TextBox();
            this.guildIdTextBox = new System.Windows.Forms.TextBox();
            this.profIdTextBox = new System.Windows.Forms.TextBox();
            this.classTextBox = new System.Windows.Forms.TextBox();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.questIdTextBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.parentTableDgv)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.childTableDgv)).BeginInit();
            this.SuspendLayout();
            // 
            // fillDgvButton
            // 
            this.fillDgvButton.Location = new System.Drawing.Point(12, 12);
            this.fillDgvButton.Name = "button1";
            this.fillDgvButton.Size = new System.Drawing.Size(109, 54);
            this.fillDgvButton.TabIndex = 0;
            this.fillDgvButton.Text = "Show parent table (GUILD)";
            this.fillDgvButton.UseVisualStyleBackColor = true;
            this.fillDgvButton.Click += new System.EventHandler(this.fillDgvButton_Click);
            // 
            // parentTableDgv
            // 
            this.parentTableDgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.parentTableDgv.Location = new System.Drawing.Point(12, 84);
            this.parentTableDgv.Name = "parentTableDgv";
            this.parentTableDgv.RowTemplate.Height = 24;
            this.parentTableDgv.Size = new System.Drawing.Size(767, 132);
            this.parentTableDgv.TabIndex = 1;
            // 
            // childTableDgv
            // 
            this.childTableDgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.childTableDgv.Location = new System.Drawing.Point(12, 251);
            this.childTableDgv.Name = "childTableDgv";
            this.childTableDgv.RowTemplate.Height = 24;
            this.childTableDgv.Size = new System.Drawing.Size(969, 150);
            this.childTableDgv.TabIndex = 2;
            // 
            // addPlayerButton
            // 
            this.addPlayerButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.addPlayerButton.Location = new System.Drawing.Point(7, 609);
            this.addPlayerButton.Name = "button2";
            this.addPlayerButton.Size = new System.Drawing.Size(105, 42);
            this.addPlayerButton.TabIndex = 3;
            this.addPlayerButton.Text = "Add player";
            this.addPlayerButton.UseVisualStyleBackColor = true;
            this.addPlayerButton.Click += new System.EventHandler(this.addPlayerButton_Click);
            // 
            // idTextBox
            // 
            this.idTextBox.Location = new System.Drawing.Point(12, 441);
            this.idTextBox.Name = "idTextBox";
            this.idTextBox.Size = new System.Drawing.Size(100, 22);
            this.idTextBox.TabIndex = 4;
            // 
            // guildIdTextBox
            // 
            this.guildIdTextBox.Location = new System.Drawing.Point(12, 553);
            this.guildIdTextBox.Name = "guildIdTextBox";
            this.guildIdTextBox.Size = new System.Drawing.Size(100, 22);
            this.guildIdTextBox.TabIndex = 5;
            // 
            // profIdTextBox
            // 
            this.profIdTextBox.Location = new System.Drawing.Point(12, 525);
            this.profIdTextBox.Name = "profIdTextBox";
            this.profIdTextBox.Size = new System.Drawing.Size(100, 22);
            this.profIdTextBox.TabIndex = 6;
            // 
            // classTextBox
            // 
            this.classTextBox.Location = new System.Drawing.Point(12, 497);
            this.classTextBox.Name = "classTextBox";
            this.classTextBox.Size = new System.Drawing.Size(100, 22);
            this.classTextBox.TabIndex = 7;
            // 
            // nameTextBox
            // 
            this.nameTextBox.Location = new System.Drawing.Point(12, 469);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(100, 22);
            this.nameTextBox.TabIndex = 8;
            // 
            // questIdTextBox
            // 
            this.questIdTextBox.Location = new System.Drawing.Point(12, 581);
            this.questIdTextBox.Name = "questIdTextBox";
            this.questIdTextBox.Size = new System.Drawing.Size(100, 22);
            this.questIdTextBox.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1083, 659);
            this.Controls.Add(this.questIdTextBox);
            this.Controls.Add(this.nameTextBox);
            this.Controls.Add(this.classTextBox);
            this.Controls.Add(this.profIdTextBox);
            this.Controls.Add(this.guildIdTextBox);
            this.Controls.Add(this.idTextBox);
            this.Controls.Add(this.addPlayerButton);
            this.Controls.Add(this.childTableDgv);
            this.Controls.Add(this.parentTableDgv);
            this.Controls.Add(this.fillDgvButton);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.parentTableDgv)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.childTableDgv)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button fillDgvButton;
        private System.Windows.Forms.DataGridView parentTableDgv;
        private System.Windows.Forms.DataGridView childTableDgv;
        private System.Windows.Forms.Button addPlayerButton;
        private System.Windows.Forms.TextBox idTextBox;
        private System.Windows.Forms.TextBox guildIdTextBox;
        private System.Windows.Forms.TextBox profIdTextBox;
        private System.Windows.Forms.TextBox classTextBox;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.TextBox questIdTextBox;
    }
}

