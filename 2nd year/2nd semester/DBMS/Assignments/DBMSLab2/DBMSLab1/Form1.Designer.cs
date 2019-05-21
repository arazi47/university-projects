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
            this.execNextQueryButton = new System.Windows.Forms.Button();
            this.dgv = new System.Windows.Forms.DataGridView();
            this.NextCommandTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            this.SuspendLayout();
            // 
            // execNextQueryButton
            // 
            this.execNextQueryButton.Location = new System.Drawing.Point(12, 418);
            this.execNextQueryButton.Name = "execNextQueryButton";
            this.execNextQueryButton.Size = new System.Drawing.Size(195, 202);
            this.execNextQueryButton.TabIndex = 0;
            this.execNextQueryButton.Text = "Execute next query";
            this.execNextQueryButton.UseVisualStyleBackColor = true;
            this.execNextQueryButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // dgv
            // 
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.Location = new System.Drawing.Point(12, 12);
            this.dgv.Name = "dgv";
            this.dgv.RowTemplate.Height = 24;
            this.dgv.Size = new System.Drawing.Size(1059, 389);
            this.dgv.TabIndex = 1;
            // 
            // NextCommandTextBox
            // 
            this.NextCommandTextBox.Location = new System.Drawing.Point(244, 443);
            this.NextCommandTextBox.Name = "NextCommandTextBox";
            this.NextCommandTextBox.Size = new System.Drawing.Size(195, 22);
            this.NextCommandTextBox.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(241, 418);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Next query:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1083, 659);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.NextCommandTextBox);
            this.Controls.Add(this.dgv);
            this.Controls.Add(this.execNextQueryButton);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button execNextQueryButton;
        private System.Windows.Forms.DataGridView dgv;
        private System.Windows.Forms.TextBox NextCommandTextBox;
        private System.Windows.Forms.Label label1;
    }
}

