namespace OpenCVApp
{
    partial class MainForm
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonForSelectImage = new System.Windows.Forms.Button();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.trackBar_ForRed = new System.Windows.Forms.TrackBar();
            this.trackBar_ForGreen = new System.Windows.Forms.TrackBar();
            this.trackBar_ForBlue = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonForSelectImage
            // 
            this.buttonForSelectImage.BackColor = System.Drawing.Color.White;
            this.buttonForSelectImage.Font = new System.Drawing.Font("メイリオ", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.buttonForSelectImage.Location = new System.Drawing.Point(12, 12);
            this.buttonForSelectImage.Name = "buttonForSelectImage";
            this.buttonForSelectImage.Size = new System.Drawing.Size(171, 54);
            this.buttonForSelectImage.TabIndex = 0;
            this.buttonForSelectImage.Text = "Image Select";
            this.buttonForSelectImage.UseVisualStyleBackColor = false;
            this.buttonForSelectImage.Click += new System.EventHandler(this.buttonForSelectImage_Click);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog";
            // 
            // pictureBox
            // 
            this.pictureBox.Location = new System.Drawing.Point(0, 0);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(692, 460);
            this.pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox.TabIndex = 1;
            this.pictureBox.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add(this.pictureBox);
            this.panel1.Location = new System.Drawing.Point(210, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(988, 579);
            this.panel1.TabIndex = 2;
            // 
            // trackBar_ForRed
            // 
            this.trackBar_ForRed.BackColor = System.Drawing.Color.White;
            this.trackBar_ForRed.LargeChange = 10;
            this.trackBar_ForRed.Location = new System.Drawing.Point(12, 86);
            this.trackBar_ForRed.Maximum = 100;
            this.trackBar_ForRed.Name = "trackBar_ForRed";
            this.trackBar_ForRed.Size = new System.Drawing.Size(171, 45);
            this.trackBar_ForRed.TabIndex = 3;
            this.trackBar_ForRed.TickFrequency = 50;
            this.trackBar_ForRed.Value = 50;
            this.trackBar_ForRed.ValueChanged += new System.EventHandler(this.BaseSettingChanged);
            // 
            // trackBar_ForGreen
            // 
            this.trackBar_ForGreen.BackColor = System.Drawing.Color.White;
            this.trackBar_ForGreen.LargeChange = 10;
            this.trackBar_ForGreen.Location = new System.Drawing.Point(12, 132);
            this.trackBar_ForGreen.Maximum = 100;
            this.trackBar_ForGreen.Name = "trackBar_ForGreen";
            this.trackBar_ForGreen.Size = new System.Drawing.Size(171, 45);
            this.trackBar_ForGreen.TabIndex = 4;
            this.trackBar_ForGreen.TickFrequency = 50;
            this.trackBar_ForGreen.Value = 50;
            this.trackBar_ForGreen.ValueChanged += new System.EventHandler(this.BaseSettingChanged);
            // 
            // trackBar_ForBlue
            // 
            this.trackBar_ForBlue.BackColor = System.Drawing.Color.White;
            this.trackBar_ForBlue.LargeChange = 10;
            this.trackBar_ForBlue.Location = new System.Drawing.Point(12, 178);
            this.trackBar_ForBlue.Maximum = 100;
            this.trackBar_ForBlue.Name = "trackBar_ForBlue";
            this.trackBar_ForBlue.Size = new System.Drawing.Size(171, 45);
            this.trackBar_ForBlue.TabIndex = 5;
            this.trackBar_ForBlue.TickFrequency = 50;
            this.trackBar_ForBlue.Value = 50;
            this.trackBar_ForBlue.ValueChanged += new System.EventHandler(this.BaseSettingChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(81, 69);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 21);
            this.label1.TabIndex = 6;
            this.label1.Text = "Red";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label2.ForeColor = System.Drawing.Color.Green;
            this.label2.Location = new System.Drawing.Point(74, 115);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(51, 21);
            this.label2.TabIndex = 7;
            this.label2.Text = "Green";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label3.ForeColor = System.Drawing.Color.Blue;
            this.label3.Location = new System.Drawing.Point(80, 160);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 21);
            this.label3.TabIndex = 8;
            this.label3.Text = "Blue";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1210, 603);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.trackBar_ForBlue);
            this.Controls.Add(this.trackBar_ForGreen);
            this.Controls.Add(this.trackBar_ForRed);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonForSelectImage);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "MainForm";
            this.Text = "OpenCV Application";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonForSelectImage;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TrackBar trackBar_ForRed;
        private System.Windows.Forms.TrackBar trackBar_ForGreen;
        private System.Windows.Forms.TrackBar trackBar_ForBlue;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

