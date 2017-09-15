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
            this.button_ForSelectImage = new System.Windows.Forms.Button();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.trackBar_ForRed = new System.Windows.Forms.TrackBar();
            this.trackBar_ForGreen = new System.Windows.Forms.TrackBar();
            this.trackBar_ForBlue = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.trackBar_ForBlur = new System.Windows.Forms.TrackBar();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.trackBar_ForZoom = new System.Windows.Forms.TrackBar();
            this.label6 = new System.Windows.Forms.Label();
            this.box_ForZoomRatio = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.effectBox = new System.Windows.Forms.ComboBox();
            this.trackBar_ForEffects = new System.Windows.Forms.TrackBar();
            this.button_ForSaveImage = new System.Windows.Forms.Button();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.button_ForSelectCascade = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label_ForDetecting = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlur)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForZoom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForEffects)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_ForSelectImage
            // 
            this.button_ForSelectImage.BackColor = System.Drawing.Color.White;
            this.button_ForSelectImage.Font = new System.Drawing.Font("メイリオ", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.button_ForSelectImage.Location = new System.Drawing.Point(11, 11);
            this.button_ForSelectImage.Name = "button_ForSelectImage";
            this.button_ForSelectImage.Size = new System.Drawing.Size(193, 48);
            this.button_ForSelectImage.TabIndex = 0;
            this.button_ForSelectImage.Text = "Select Image";
            this.button_ForSelectImage.UseVisualStyleBackColor = false;
            this.button_ForSelectImage.Click += new System.EventHandler(this.button_ForSelectImageClick);
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
            this.panel1.Location = new System.Drawing.Point(217, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(988, 630);
            this.panel1.TabIndex = 2;
            // 
            // trackBar_ForRed
            // 
            this.trackBar_ForRed.BackColor = System.Drawing.Color.White;
            this.trackBar_ForRed.LargeChange = 10;
            this.trackBar_ForRed.Location = new System.Drawing.Point(6, 32);
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
            this.trackBar_ForGreen.Location = new System.Drawing.Point(6, 87);
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
            this.trackBar_ForBlue.Location = new System.Drawing.Point(6, 138);
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
            this.label1.Location = new System.Drawing.Point(76, 13);
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
            this.label2.Location = new System.Drawing.Point(67, 68);
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
            this.label3.Location = new System.Drawing.Point(71, 119);
            this.label3.Margin = new System.Windows.Forms.Padding(0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 21);
            this.label3.TabIndex = 8;
            this.label3.Text = "Blue";
            // 
            // trackBar_ForBlur
            // 
            this.trackBar_ForBlur.BackColor = System.Drawing.Color.White;
            this.trackBar_ForBlur.LargeChange = 10;
            this.trackBar_ForBlur.Location = new System.Drawing.Point(2, 197);
            this.trackBar_ForBlur.Maximum = 100;
            this.trackBar_ForBlur.Name = "trackBar_ForBlur";
            this.trackBar_ForBlur.Size = new System.Drawing.Size(185, 45);
            this.trackBar_ForBlur.TabIndex = 9;
            this.trackBar_ForBlur.TickFrequency = 50;
            this.trackBar_ForBlur.Value = 50;
            this.trackBar_ForBlur.ValueChanged += new System.EventHandler(this.BaseSettingChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("メイリオ", 10F);
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(6, 178);
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
            this.label5.Location = new System.Drawing.Point(144, 181);
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
            this.trackBar_ForZoom.Location = new System.Drawing.Point(344, 655);
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
            this.label6.Location = new System.Drawing.Point(224, 656);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 24);
            this.label6.TabIndex = 13;
            this.label6.Text = "Zoom Ratio";
            // 
            // box_ForZoomRatio
            // 
            this.box_ForZoomRatio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.box_ForZoomRatio.BackColor = System.Drawing.Color.White;
            this.box_ForZoomRatio.Font = new System.Drawing.Font("メイリオ", 12F);
            this.box_ForZoomRatio.Location = new System.Drawing.Point(1039, 653);
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
            this.label7.Location = new System.Drawing.Point(1155, 659);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(26, 24);
            this.label7.TabIndex = 15;
            this.label7.Text = "％";
            // 
            // effectBox
            // 
            this.effectBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.effectBox.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.effectBox.Font = new System.Drawing.Font("メイリオ", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.effectBox.FormattingEnabled = true;
            this.effectBox.Location = new System.Drawing.Point(13, 23);
            this.effectBox.Margin = new System.Windows.Forms.Padding(2);
            this.effectBox.Name = "effectBox";
            this.effectBox.Size = new System.Drawing.Size(169, 32);
            this.effectBox.TabIndex = 19;
            this.effectBox.TextChanged += new System.EventHandler(this.effectBox_TextChanged);
            // 
            // trackBar_ForEffects
            // 
            this.trackBar_ForEffects.BackColor = System.Drawing.Color.White;
            this.trackBar_ForEffects.LargeChange = 10;
            this.trackBar_ForEffects.Location = new System.Drawing.Point(7, 56);
            this.trackBar_ForEffects.Margin = new System.Windows.Forms.Padding(0);
            this.trackBar_ForEffects.Maximum = 100;
            this.trackBar_ForEffects.Name = "trackBar_ForEffects";
            this.trackBar_ForEffects.Size = new System.Drawing.Size(171, 45);
            this.trackBar_ForEffects.TabIndex = 20;
            this.trackBar_ForEffects.TickFrequency = 50;
            this.trackBar_ForEffects.ValueChanged += new System.EventHandler(this.trackBar_ForEffects_ValueChanged);
            // 
            // button_ForSaveImage
            // 
            this.button_ForSaveImage.BackColor = System.Drawing.Color.White;
            this.button_ForSaveImage.Font = new System.Drawing.Font("メイリオ", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.button_ForSaveImage.Location = new System.Drawing.Point(6, 636);
            this.button_ForSaveImage.Name = "button_ForSaveImage";
            this.button_ForSaveImage.Size = new System.Drawing.Size(198, 45);
            this.button_ForSaveImage.TabIndex = 21;
            this.button_ForSaveImage.Text = "Save Image";
            this.button_ForSaveImage.UseVisualStyleBackColor = false;
            this.button_ForSaveImage.Click += new System.EventHandler(this.button_ForSaveImage_Click);
            // 
            // trackBar2
            // 
            this.trackBar2.BackColor = System.Drawing.Color.White;
            this.trackBar2.LargeChange = 10;
            this.trackBar2.Location = new System.Drawing.Point(7, 94);
            this.trackBar2.Maximum = 100;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(171, 45);
            this.trackBar2.TabIndex = 24;
            this.trackBar2.TickFrequency = 50;
            this.trackBar2.Value = 50;
            // 
            // button_ForSelectCascade
            // 
            this.button_ForSelectCascade.BackColor = System.Drawing.Color.White;
            this.button_ForSelectCascade.Font = new System.Drawing.Font("メイリオ", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.button_ForSelectCascade.Location = new System.Drawing.Point(7, 26);
            this.button_ForSelectCascade.Margin = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.button_ForSelectCascade.Name = "button_ForSelectCascade";
            this.button_ForSelectCascade.Size = new System.Drawing.Size(175, 31);
            this.button_ForSelectCascade.TabIndex = 26;
            this.button_ForSelectCascade.Text = "Select Training Data";
            this.button_ForSelectCascade.UseVisualStyleBackColor = false;
            this.button_ForSelectCascade.Click += new System.EventHandler(this.button_ForSelectCascade_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.comboBox1.Font = new System.Drawing.Font("メイリオ", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9"});
            this.comboBox1.Location = new System.Drawing.Point(131, 127);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(2);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(47, 32);
            this.comboBox1.TabIndex = 27;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.White;
            this.button1.Font = new System.Drawing.Font("メイリオ", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.button1.Location = new System.Drawing.Point(41, 155);
            this.button1.Margin = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(112, 31);
            this.button1.TabIndex = 28;
            this.button1.Text = "Run";
            this.button1.UseVisualStyleBackColor = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label_ForDetecting);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.button_ForSelectCascade);
            this.groupBox1.Controls.Add(this.comboBox1);
            this.groupBox1.Controls.Add(this.trackBar2);
            this.groupBox1.Font = new System.Drawing.Font("メイリオ", 9F);
            this.groupBox1.Location = new System.Drawing.Point(11, 444);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(193, 188);
            this.groupBox1.TabIndex = 29;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Object Detecting";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.trackBar_ForEffects);
            this.groupBox2.Controls.Add(this.effectBox);
            this.groupBox2.Font = new System.Drawing.Font("メイリオ", 9F);
            this.groupBox2.Location = new System.Drawing.Point(11, 313);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(193, 113);
            this.groupBox2.TabIndex = 30;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Parctical Effects";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.trackBar_ForRed);
            this.groupBox3.Controls.Add(this.trackBar_ForGreen);
            this.groupBox3.Controls.Add(this.trackBar_ForBlue);
            this.groupBox3.Controls.Add(this.trackBar_ForBlur);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Font = new System.Drawing.Font("メイリオ", 9F);
            this.groupBox3.Location = new System.Drawing.Point(11, 60);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(193, 246);
            this.groupBox3.TabIndex = 31;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Base Effects";
            // 
            // label_ForDetecting
            // 
            this.label_ForDetecting.BackColor = System.Drawing.Color.GhostWhite;
            this.label_ForDetecting.Location = new System.Drawing.Point(11, 64);
            this.label_ForDetecting.Name = "label_ForDetecting";
            this.label_ForDetecting.Size = new System.Drawing.Size(171, 18);
            this.label_ForDetecting.TabIndex = 29;
            this.label_ForDetecting.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1210, 688);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.button_ForSaveImage);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.box_ForZoomRatio);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.trackBar_ForZoom);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.button_ForSelectImage);
            this.Name = "MainForm";
            this.Text = "OpenCV Application";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForRed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForGreen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForBlur)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForZoom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar_ForEffects)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_ForSelectImage;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TrackBar trackBar_ForRed;
        private System.Windows.Forms.TrackBar trackBar_ForGreen;
        private System.Windows.Forms.TrackBar trackBar_ForBlue;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TrackBar trackBar_ForBlur;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TrackBar trackBar_ForZoom;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox box_ForZoomRatio;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox effectBox;
        private System.Windows.Forms.TrackBar trackBar_ForEffects;
        private System.Windows.Forms.Button button_ForSaveImage;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.Button button_ForSelectCascade;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label_ForDetecting;
    }
}

