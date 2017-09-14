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
            this.trackBar_forBlur = new System.Windows.Forms.TrackBar();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.trackBar_ForZoom = new System.Windows.Forms.TrackBar();
            this.label6 = new System.Windows.Forms.Label();
            this.box_ForZoomRatio = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.effectBox = new System.Windows.Forms.ComboBox();
            this.trackBar_ForEffects = new System.Windows.Forms.TrackBar();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_forBlur)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForZoom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForEffects)).BeginInit();
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
            this.openFileDialog.Filter = "Image Files (*.bmp, *.jpg, *.jpeg., *.png)|*.bmp;*.jpg; *.jpeg; *.png;";
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
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
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
            this.label1.Location = new System.Drawing.Point(81, 65);
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
            this.label2.Location = new System.Drawing.Point(74, 110);
            this.label2.Margin = new System.Windows.Forms.Padding(0);
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
            this.label3.Location = new System.Drawing.Point(79, 156);
            this.label3.Margin = new System.Windows.Forms.Padding(0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 21);
            this.label3.TabIndex = 8;
            this.label3.Text = "Blue";
            // 
            // trackBar_forBlur
            // 
            this.trackBar_forBlur.BackColor = System.Drawing.Color.White;
            this.trackBar_forBlur.LargeChange = 10;
            this.trackBar_forBlur.Location = new System.Drawing.Point(12, 227);
            this.trackBar_forBlur.Maximum = 100;
            this.trackBar_forBlur.Name = "trackBar_forBlur";
            this.trackBar_forBlur.Size = new System.Drawing.Size(171, 45);
            this.trackBar_forBlur.TabIndex = 9;
            this.trackBar_forBlur.TickFrequency = 50;
            this.trackBar_forBlur.Value = 50;
            this.trackBar_forBlur.ValueChanged += new System.EventHandler(this.BaseSettingChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(19, 211);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 21);
            this.label4.TabIndex = 10;
            this.label4.Text = "Sharp";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(145, 211);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 21);
            this.label5.TabIndex = 11;
            this.label5.Text = "Blur";
            // 
            // trackBar_ForZoom
            // 
            this.trackBar_ForZoom.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBar_ForZoom.BackColor = System.Drawing.Color.White;
            this.trackBar_ForZoom.LargeChange = 10;
            this.trackBar_ForZoom.Location = new System.Drawing.Point(344, 604);
            this.trackBar_ForZoom.Maximum = 150;
            this.trackBar_ForZoom.Minimum = 10;
            this.trackBar_ForZoom.Name = "trackBar_ForZoom";
            this.trackBar_ForZoom.Size = new System.Drawing.Size(683, 45);
            this.trackBar_ForZoom.TabIndex = 12;
            this.trackBar_ForZoom.TickFrequency = 10;
            this.trackBar_ForZoom.Value = 100;
            this.trackBar_ForZoom.ValueChanged += new System.EventHandler(this.trackBar_ForZoom_ValueChanged);
            // 
            // label6
            // 
            this.label6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("メイリオ", 12F);
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(224, 605);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 24);
            this.label6.TabIndex = 13;
            this.label6.Text = "Zoom Ratio";
            // 
            // box_ForZoomRatio
            // 
            this.box_ForZoomRatio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.box_ForZoomRatio.Font = new System.Drawing.Font("メイリオ", 12F);
            this.box_ForZoomRatio.Location = new System.Drawing.Point(1039, 602);
            this.box_ForZoomRatio.Name = "box_ForZoomRatio";
            this.box_ForZoomRatio.ReadOnly = true;
            this.box_ForZoomRatio.Size = new System.Drawing.Size(110, 31);
            this.box_ForZoomRatio.TabIndex = 14;
            this.box_ForZoomRatio.Text = "100";
            this.box_ForZoomRatio.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label7
            // 
            this.label7.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("メイリオ", 12F);
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(1155, 608);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(26, 24);
            this.label7.TabIndex = 15;
            this.label7.Text = "％";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label8.ForeColor = System.Drawing.Color.Black;
            this.label8.Location = new System.Drawing.Point(40, 268);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(117, 21);
            this.label8.TabIndex = 18;
            this.label8.Text = "Practical Effects";
            // 
            // effectBox
            // 
            this.effectBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.effectBox.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.effectBox.Font = new System.Drawing.Font("メイリオ", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.effectBox.FormattingEnabled = true;
            this.effectBox.Location = new System.Drawing.Point(23, 291);
            this.effectBox.Margin = new System.Windows.Forms.Padding(2);
            this.effectBox.Name = "effectBox";
            this.effectBox.Size = new System.Drawing.Size(160, 32);
            this.effectBox.TabIndex = 19;
            this.effectBox.TextChanged += new System.EventHandler(this.effectBox_TextChanged);
            // 
            // trackBar_ForEffects
            // 
            this.trackBar_ForEffects.BackColor = System.Drawing.Color.White;
            this.trackBar_ForEffects.LargeChange = 10;
            this.trackBar_ForEffects.Location = new System.Drawing.Point(12, 329);
            this.trackBar_ForEffects.Maximum = 100;
            this.trackBar_ForEffects.Name = "trackBar_ForEffects";
            this.trackBar_ForEffects.Size = new System.Drawing.Size(171, 45);
            this.trackBar_ForEffects.TabIndex = 20;
            this.trackBar_ForEffects.TickFrequency = 50;
            this.trackBar_ForEffects.ValueChanged += new System.EventHandler(this.trackBar_ForEffects_ValueChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1210, 637);
            this.Controls.Add(this.trackBar_ForEffects);
            this.Controls.Add(this.effectBox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.box_ForZoomRatio);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.trackBar_ForZoom);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.trackBar_forBlur);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.trackBar_ForBlue);
            this.Controls.Add(this.trackBar_ForGreen);
            this.Controls.Add(this.trackBar_ForRed);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonForSelectImage);
            this.Controls.Add(this.label1);
            this.Name = "MainForm";
            this.Text = "OpenCV Application";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_forBlur)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForZoom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForEffects)).EndInit();
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
        private System.Windows.Forms.TrackBar trackBar_forBlur;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TrackBar trackBar_ForZoom;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox box_ForZoomRatio;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox effectBox;
        private System.Windows.Forms.TrackBar trackBar_ForEffects;
    }
}

