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
                    Bitmap bitmap = imager.read(openFileDialog.FileName);

                    //ImageオブジェクトのGraphicsオブジェクトを作成する
                    //Graphics g = Graphics.FromImage(bitmap);

                    pictureBox.Image = bitmap;
                } catch(Exception) {

                }
            }
        }
    }
}
