using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OpenCVApp
{
    public partial class MainForm : Form
    {

        private ImagingWrapper imager;
        private Bitmap actualSizeImage;
        private double zoomRatio = 1.0;

        public MainForm()
        {
            InitializeComponent();
            imager = new ImagingWrapper();
        }

        private void buttonForSelectImage_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    imager.read(openFileDialog.FileName);
                    UpdateImage();
                }
                catch (System.IO.IOException exeption)
                {
                    MessageBox.Show("サポートされていないファイルフォーマットです。" + Environment.NewLine
                        + exeption.Message, "Error",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                } 
            }
        }

        private void UpdateImage()
        {
            if (actualSizeImage != null)
            {
                actualSizeImage.Dispose();
            }
            actualSizeImage = imager.getImage();
            DisplayImage();
        }

        private void DisplayImage()
        {
            if (actualSizeImage == null)
            {
                return;
            }
            if (pictureBox.Image != null)
            {
                pictureBox.Image.Dispose();
            }
            pictureBox.Image = new Bitmap(actualSizeImage, 
                (int) Math.Round(actualSizeImage.Width * zoomRatio),
                (int) Math.Round(actualSizeImage.Height * zoomRatio));
        }


        private void BaseSettingChanged(object sender, EventArgs e)
        {
            imager.updateBaseSettings(
                trackBar_ForRed.Value,
                trackBar_ForGreen.Value,
                trackBar_ForBlue.Value,
                trackBar_forBlur.Value);
            UpdateImage();
        }

        private void trackBar_ForZoom_ValueChanged(object sender, EventArgs e)
        {
            box_ForZoomRatio.Text = trackBar_ForZoom.Value.ToString();
            zoomRatio = trackBar_ForZoom.Value / 100.0; /* 百分率から割合に戻す */
            DisplayImage();
        }
    }
}
