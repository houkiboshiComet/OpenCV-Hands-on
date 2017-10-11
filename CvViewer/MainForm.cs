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
        private const int DEFAULT_MIN_NEIGHBORS = 3; /*< opencvのdetectmultiscaleの引数minneighborsのデフォルト値 */ 

        public MainForm()
        {
            InitializeComponent();
            imager = new ImagingWrapper();
        }
        private void resetEffectComponent()
        {
            trackBar_ForBlue.Value = ImagingWrapper.CENTRAL_SETTING_VALUE();
            trackBar_ForGreen.Value = ImagingWrapper.CENTRAL_SETTING_VALUE();
            trackBar_ForRed.Value = ImagingWrapper.CENTRAL_SETTING_VALUE();
            trackBar_ForBlur.Value = ImagingWrapper.CENTRAL_SETTING_VALUE();

            trackBar_ForEffects.Value = ImagingWrapper.MIN_SETTING_VALUE();
            trackBar_ForObjectDetection.Value = ImagingWrapper.MIN_SETTING_VALUE();

            effectBox.SelectedIndex = 0;
            comboBox_ForMinNeighbors.Text = DEFAULT_MIN_NEIGHBORS.ToString();
        }


        private void button_ForSelectImageClick(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    resetEffectComponent();
                    imager.load(openFileDialog.FileName);
                    UpdateImage();
                }
                catch (ImagingException exception)
                {
                    MessageBox.Show("サポートされていないファイルフォーマットです。" + Environment.NewLine
                        + exception.Message, "Error",
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
                (int)Math.Round(actualSizeImage.Width * zoomRatio),
                (int)Math.Round(actualSizeImage.Height * zoomRatio));
        }


        private void BaseSettingChanged(object sender, EventArgs e)
        {
            imager.updateBaseSettings(
                trackBar_ForRed.Value,
                trackBar_ForGreen.Value,
                trackBar_ForBlue.Value,
                trackBar_ForBlur.Value);
            UpdateImage();
        }

        private void trackBar_ForZoom_ValueChanged(object sender, EventArgs e)
        {
            box_ForZoomRatio.Text = trackBar_ForZoom.Value.ToString();
            zoomRatio = trackBar_ForZoom.Value / 100.0; /* 百分率から割合に戻す */
            DisplayImage();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
           
            effectBox.Items.AddRange(ImagingWrapper.getEffectNames());
            effectBox.SelectedIndex = 0;
            comboBox_ForMinNeighbors.Text = DEFAULT_MIN_NEIGHBORS.ToString(); 
        }

        private void effectBox_TextChanged(object sender, EventArgs e)
        {
            trackBar_ForEffects.Value = 0;
        }

        private void trackBar_ForEffects_ValueChanged(object sender, EventArgs e)
        {
            imager.updateEffect(effectBox.Text, trackBar_ForEffects.Value);
            UpdateImage();
        }

        private void button_ForSaveImage_Click(object sender, EventArgs e)
        {
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    imager.save(saveFileDialog.FileName);
                }
                catch (ImagingException exception)
                {
                    MessageBox.Show("画像保存に失敗しました。" + Environment.NewLine
                        + exception.Message, "Error",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
        }

        private void button_ForSelectCascade_Click(object sender, EventArgs e)
        {
            if (openXmlDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    imager.setCascadeData(openXmlDialog.FileName);
                    label_ForDetecting.Text = System.IO.Path.GetFileName(openXmlDialog.FileName);
                }
                catch (ImagingException exception)
                {
                    MessageBox.Show("学習データの読み込みに失敗しました。" + Environment.NewLine
                        + exception.Message, "Error",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void ObjectDetectPropetis_Changed(object sender, EventArgs e)
        {
            if (actualSizeImage == null) {
                return;
            }
            if ( label_ForDetecting.Text.Equals(String.Empty))
            {
                MessageBox.Show("[Select Training Data]ボタンから学習データを選択して下さい。", "Error",
                   MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            try
            {
                imager.detectObject(trackBar_ForObjectDetection.Value, Int32.Parse(comboBox_ForMinNeighbors.Text));
                UpdateImage();
            }
            catch (ImagingException exception)
            {
                MessageBox.Show("物体検出に失敗しました。" + Environment.NewLine
                       + exception.Message, "Error",
                       MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


    }
}
