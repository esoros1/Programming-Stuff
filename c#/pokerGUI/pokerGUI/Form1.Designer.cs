namespace pokerGUI
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.bottom = new System.Windows.Forms.FlowLayoutPanel();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.computerLabel = new System.Windows.Forms.Label();
            this.computerCardLabel = new System.Windows.Forms.Label();
            this.middle = new System.Windows.Forms.Panel();
            this.endButton = new System.Windows.Forms.Button();
            this.drawButton = new System.Windows.Forms.Button();
            this.top = new System.Windows.Forms.FlowLayoutPanel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.playerLabel = new System.Windows.Forms.Label();
            this.playerCardText = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.bottom.SuspendLayout();
            this.middle.SuspendLayout();
            this.top.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.bottom);
            this.panel1.Controls.Add(this.middle);
            this.panel1.Controls.Add(this.top);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1011, 573);
            this.panel1.TabIndex = 0;
            // 
            // bottom
            // 
            this.bottom.Controls.Add(this.button6);
            this.bottom.Controls.Add(this.button7);
            this.bottom.Controls.Add(this.button8);
            this.bottom.Controls.Add(this.button9);
            this.bottom.Controls.Add(this.button10);
            this.bottom.Controls.Add(this.computerLabel);
            this.bottom.Controls.Add(this.computerCardLabel);
            this.bottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.bottom.Enabled = false;
            this.bottom.Location = new System.Drawing.Point(0, 350);
            this.bottom.Name = "bottom";
            this.bottom.Size = new System.Drawing.Size(1007, 219);
            this.bottom.TabIndex = 2;
            // 
            // button6
            // 
            this.button6.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button6.Enabled = false;
            this.button6.Location = new System.Drawing.Point(3, 3);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(138, 197);
            this.button6.TabIndex = 0;
            this.button6.UseVisualStyleBackColor = true;
            // 
            // button7
            // 
            this.button7.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button7.Enabled = false;
            this.button7.Location = new System.Drawing.Point(147, 3);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(154, 197);
            this.button7.TabIndex = 1;
            this.button7.UseVisualStyleBackColor = true;
            // 
            // button8
            // 
            this.button8.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button8.Enabled = false;
            this.button8.Location = new System.Drawing.Point(307, 3);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(154, 197);
            this.button8.TabIndex = 2;
            this.button8.UseVisualStyleBackColor = true;
            // 
            // button9
            // 
            this.button9.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button9.Enabled = false;
            this.button9.Location = new System.Drawing.Point(467, 3);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(154, 197);
            this.button9.TabIndex = 3;
            this.button9.UseVisualStyleBackColor = true;
            // 
            // button10
            // 
            this.button10.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button10.Enabled = false;
            this.button10.Location = new System.Drawing.Point(627, 3);
            this.button10.Name = "button10";
            this.button10.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.button10.Size = new System.Drawing.Size(154, 197);
            this.button10.TabIndex = 4;
            this.button10.UseVisualStyleBackColor = true;
            // 
            // computerLabel
            // 
            this.computerLabel.AutoSize = true;
            this.computerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.computerLabel.Location = new System.Drawing.Point(787, 0);
            this.computerLabel.Name = "computerLabel";
            this.computerLabel.Size = new System.Drawing.Size(79, 20);
            this.computerLabel.TabIndex = 6;
            this.computerLabel.Text = "Computer";
            // 
            // computerCardLabel
            // 
            this.computerCardLabel.AutoSize = true;
            this.computerCardLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.computerCardLabel.Location = new System.Drawing.Point(872, 0);
            this.computerCardLabel.Name = "computerCardLabel";
            this.computerCardLabel.Size = new System.Drawing.Size(0, 20);
            this.computerCardLabel.TabIndex = 7;
            // 
            // middle
            // 
            this.middle.Controls.Add(this.endButton);
            this.middle.Controls.Add(this.drawButton);
            this.middle.Dock = System.Windows.Forms.DockStyle.Top;
            this.middle.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.middle.Location = new System.Drawing.Point(0, 213);
            this.middle.Name = "middle";
            this.middle.Size = new System.Drawing.Size(1007, 145);
            this.middle.TabIndex = 1;
            // 
            // endButton
            // 
            this.endButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.endButton.Location = new System.Drawing.Point(467, 40);
            this.endButton.Name = "endButton";
            this.endButton.Size = new System.Drawing.Size(305, 71);
            this.endButton.TabIndex = 1;
            this.endButton.Text = "end";
            this.endButton.UseVisualStyleBackColor = true;
            this.endButton.Click += new System.EventHandler(this.end_Click);
            // 
            // drawButton
            // 
            this.drawButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.drawButton.Location = new System.Drawing.Point(22, 40);
            this.drawButton.Name = "drawButton";
            this.drawButton.Size = new System.Drawing.Size(305, 71);
            this.drawButton.TabIndex = 0;
            this.drawButton.Text = "draw: 3 turns left";
            this.drawButton.UseVisualStyleBackColor = true;
            this.drawButton.Click += new System.EventHandler(this.draw_Click);
            // 
            // top
            // 
            this.top.Controls.Add(this.button1);
            this.top.Controls.Add(this.button2);
            this.top.Controls.Add(this.button3);
            this.top.Controls.Add(this.button4);
            this.top.Controls.Add(this.button5);
            this.top.Controls.Add(this.playerLabel);
            this.top.Controls.Add(this.playerCardText);
            this.top.Dock = System.Windows.Forms.DockStyle.Top;
            this.top.Location = new System.Drawing.Point(0, 0);
            this.top.Name = "top";
            this.top.Size = new System.Drawing.Size(1007, 213);
            this.top.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button1.Location = new System.Drawing.Point(3, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(138, 197);
            this.button1.TabIndex = 0;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.button_Click);
            // 
            // button2
            // 
            this.button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button2.Location = new System.Drawing.Point(147, 3);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(154, 197);
            this.button2.TabIndex = 1;
            this.button2.UseVisualStyleBackColor = true;
            this.button2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.button_Click);
            // 
            // button3
            // 
            this.button3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button3.Location = new System.Drawing.Point(307, 3);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(154, 197);
            this.button3.TabIndex = 2;
            this.button3.UseVisualStyleBackColor = true;
            this.button3.MouseClick += new System.Windows.Forms.MouseEventHandler(this.button_Click);
            // 
            // button4
            // 
            this.button4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button4.Location = new System.Drawing.Point(467, 3);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(154, 197);
            this.button4.TabIndex = 3;
            this.button4.UseVisualStyleBackColor = true;
            this.button4.MouseClick += new System.Windows.Forms.MouseEventHandler(this.button_Click);
            // 
            // button5
            // 
            this.button5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button5.Location = new System.Drawing.Point(627, 3);
            this.button5.Name = "button5";
            this.button5.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.button5.Size = new System.Drawing.Size(154, 197);
            this.button5.TabIndex = 4;
            this.button5.UseVisualStyleBackColor = true;
            this.button5.MouseClick += new System.Windows.Forms.MouseEventHandler(this.button_Click);
            // 
            // playerLabel
            // 
            this.playerLabel.AutoSize = true;
            this.playerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.playerLabel.Location = new System.Drawing.Point(787, 0);
            this.playerLabel.Name = "playerLabel";
            this.playerLabel.Size = new System.Drawing.Size(65, 20);
            this.playerLabel.TabIndex = 6;
            this.playerLabel.Text = "Player 1";
            this.playerLabel.Click += new System.EventHandler(this.playerLabel_Click);
            // 
            // playerCardText
            // 
            this.playerCardText.AutoSize = true;
            this.playerCardText.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.playerCardText.Location = new System.Drawing.Point(858, 0);
            this.playerCardText.Name = "playerCardText";
            this.playerCardText.Size = new System.Drawing.Size(0, 20);
            this.playerCardText.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Green;
            this.ClientSize = new System.Drawing.Size(1011, 573);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.bottom.ResumeLayout(false);
            this.bottom.PerformLayout();
            this.middle.ResumeLayout(false);
            this.top.ResumeLayout(false);
            this.top.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.FlowLayoutPanel top;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label playerLabel;
        private System.Windows.Forms.Panel middle;
        private System.Windows.Forms.Button drawButton;
        private System.Windows.Forms.Button endButton;
        private System.Windows.Forms.FlowLayoutPanel bottom;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Label computerLabel;
        private System.Windows.Forms.Label playerCardText;
        private System.Windows.Forms.Label computerCardLabel;
    }
}

