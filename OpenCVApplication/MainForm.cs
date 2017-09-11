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
            if (pictureBox.Image != null)
            {
                pictureBox.Image.Dispose();
            }
            pictureBox.Image = imager.getImage();
        }

        private void BaseSettingChanged(object sender, EventArgs e)
        {
            imager.updateBaseSettings(
                trackBar_ForRed.Value,
                trackBar_ForGreen.Value,
                trackBar_ForBlue.Value,
                0);
            UpdateImage();
        }
    }
}
