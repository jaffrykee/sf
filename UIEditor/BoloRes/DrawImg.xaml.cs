using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml;
using System.Data;
using System.Windows.Media.Animation;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// DrawImg.xaml 的交互逻辑
	/// </summary>
	
	public struct AniNode
	{
		public string aniPath;
		public XmlElement aniXe;
	}

	public partial class DrawImg : Grid
	{
		public XmlControl m_rootControl;
		public double m_imgHeight;
		public double m_imgWidth;
		public bool m_loaded;

		public XmlElement m_xe;
		public string m_path;
		public List<AniNode> m_aniNodes;
		public bool m_enLoop;
		public double m_aniFrameTime;
		public float m_perDpiX;
		public float m_perDpiY;

		private double m_dW;
		private double m_dH;

		public DrawImg(XmlElement xe, string rootPath, XmlControl rootControl)
		{
			InitializeComponent();
			m_xe = xe;
			m_loaded = false;
			m_path = "";
			m_aniNodes = new List<AniNode>();
			m_rootControl = rootControl;

			string ImageName = m_xe.GetAttribute("ImageName");

			string fileName = ImageName.Substring(ImageName.LastIndexOf(".") + 1, (ImageName.Length - ImageName.LastIndexOf(".") - 1));
			string folderName = ImageName.Substring(ImageName.LastIndexOf("\\") + 1, (ImageName.LastIndexOf(".") - ImageName.LastIndexOf("\\") - 1));
			fileName += ".png";
			string path = rootPath + "\\" + "images" + "\\" + folderName + "\\" + fileName;
			AniNode aniNode = new AniNode();
			aniNode.aniPath = path;
			aniNode.aniXe = m_xe;
			m_aniNodes.Add(aniNode);

			XmlNodeList xnl = m_xe.ChildNodes;
			if (m_xe.ChildNodes.Count > 0)
			{
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xeAni = (XmlElement)xnf;

						if (xeAni.Name == "animation")
						{
							if (xeAni.GetAttribute("loop") == "true")
							{
								m_enLoop = true;
							}
							else
							{
								m_enLoop = false;
							}
							XmlNodeList xnlAni = xeAni.ChildNodes;
							foreach (XmlNode xnfFrame in xnlAni)
							{
								if (xnfFrame.NodeType == XmlNodeType.Element)
								{
									XmlElement xeFrame = (XmlElement)xnfFrame;
									if (xeFrame.Name == "frame")
									{
										if (xeFrame.GetAttribute("image") != "")
										{
											string frameImageName = xeFrame.GetAttribute("image");
											string frameFileName = frameImageName.Substring(frameImageName.LastIndexOf(".") + 1, (frameImageName.Length - frameImageName.LastIndexOf(".") - 1));
											string frameFolderName = frameImageName.Substring(frameImageName.LastIndexOf("\\") + 1, (frameImageName.LastIndexOf(".") - frameImageName.LastIndexOf("\\") - 1));

											frameFileName += ".png";
											string framePath = rootPath + "\\" + "images" + "\\" + frameFolderName + "\\" + frameFileName;

											if (!System.IO.File.Exists(framePath))
											{
												m_rootControl.textContent.Text += "没有找到文件：\"" + m_path + "\"\r\n";
											}
											else
											{
												AniNode frameNode = new AniNode();
												frameNode.aniPath = framePath;
												frameNode.aniXe = xeFrame;
												m_aniNodes.Add(frameNode);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			m_path = path;
			m_aniFrameTime = 0.17f;
		}

		private void drawFrame(AniNode aniNode, ref int iFrame, ref double sTime)
		{
			double dW = 0.0d;
			double dH = 0.0d;
			double dX = 0.0d;
			double dY = 0.0d;

			if (aniNode.aniXe.Name == "frame" || aniNode.aniXe.Name == "imageShape")
			{
				#region frame
				if (aniNode.aniXe.Name == "frame")
				{
					foreach (XmlAttribute att in aniNode.aniXe.Attributes)
					{
						switch(att.Name)
						{
							case "time":
							case "image":
							case "w":
							case "h":
							case "x":
							case "y":
							case "Anchor":
							case "angle":
								break;
							default:
								{
									m_rootControl.textContent.Text += ("attr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
								}
								break;
						}
					}

					#region time
					if (aniNode.aniXe.GetAttribute("time") != "")
					{
						sTime = double.Parse(aniNode.aniXe.GetAttribute("time")) / 1000;
					}
					else
					{
						if (iFrame > 0)
						{
							sTime += m_aniFrameTime;
						}
					}
					#endregion

					#region w & h
					if (aniNode.aniXe.GetAttribute("w") != "")
					{
						dW = double.Parse(aniNode.aniXe.GetAttribute("w"));

						DiscreteObjectKeyFrame aniWidth =
							new DiscreteObjectKeyFrame(
								new GridLength(dW),
								KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
							);
						mx_aniW.KeyFrames.Add(aniWidth);
					}
					else
					{
						dW = m_dW;
					}
					if (aniNode.aniXe.GetAttribute("h") != "")
					{
						dH = double.Parse(aniNode.aniXe.GetAttribute("h"));

						DiscreteObjectKeyFrame aniHeight =
							new DiscreteObjectKeyFrame(
								new GridLength(dH),
								KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
							);
						mx_aniH.KeyFrames.Add(aniHeight);
					}
					else
					{
						dH = m_dH;
					}
					#endregion

					#region x , y & Anchor
					if (aniNode.aniXe.GetAttribute("x") != "" || aniNode.aniXe.GetAttribute("y") != "" || aniNode.aniXe.GetAttribute("Anchor") != "")
					{

						if (aniNode.aniXe.GetAttribute("x") != "")
						{
							dX = double.Parse(aniNode.aniXe.GetAttribute("x"));
						}
						else
						{
							if(m_xe.GetAttribute("X") != "")
							{
								dX = double.Parse(m_xe.GetAttribute("X"));
							}
						}
						if (aniNode.aniXe.GetAttribute("y") != "")
						{
							dY = double.Parse(aniNode.aniXe.GetAttribute("y"));
						}
						else
						{
							if (m_xe.GetAttribute("Y") != "")
							{
								dY = double.Parse(m_xe.GetAttribute("Y"));
							}
						}

						if (aniNode.aniXe.GetAttribute("Anchor") != "")
						{
							int anchor = int.Parse(aniNode.aniXe.GetAttribute("Anchor"));

							if ((anchor & 0x01) > 0)
							{
								//水平居中
								dX = dX + (((Canvas)this.Parent).Width - dW) / 2;
							}
							if ((anchor & 0x02) > 0)
							{
								//垂直居中
								dY = dY + (((Canvas)this.Parent).Height - dH) / 2;
							}
							if ((anchor & 0x04) > 0)
							{
								//左对齐
							}
							if ((anchor & 0x08) > 0)
							{
								//右对齐
								dX = dX + (((Canvas)this.Parent).Width - dW);
							}
							if ((anchor & 0x10) > 0)
							{
								//上对齐
							}
							if ((anchor & 0x20) > 0)
							{
								//底部对齐
								dY = dY + (((Canvas)this.Parent).Height - dH);
							}
						}

						DiscreteDoubleKeyFrame aniX =
							new DiscreteDoubleKeyFrame(
								dX,
								KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
							);
						DiscreteDoubleKeyFrame aniY =
							new DiscreteDoubleKeyFrame(
								dY,
								KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
							);
						mx_aniX.KeyFrames.Add(aniX);
						mx_aniY.KeyFrames.Add(aniY);
					}
					#endregion

					#region angle
					if (aniNode.aniXe.GetAttribute("angle") != "")
					{
						double dAngle = double.Parse(aniNode.aniXe.GetAttribute("angle"));

						DiscreteDoubleKeyFrame aniAngle =
							new DiscreteDoubleKeyFrame(
								dAngle,
								KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
							);
						mx_aniAngle.KeyFrames.Add(aniAngle);
					}
					#endregion
				}
				#endregion frame
				DiscreteStringKeyFrame aniFrame =
					new DiscreteStringKeyFrame(
						aniNode.aniPath,
						KeyTime.FromTimeSpan(TimeSpan.FromSeconds(sTime))
					);
				mx_aniFrame.KeyFrames.Add(aniFrame);
				iFrame++;
			}
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				MainWindow pW = Window.GetWindow(this) as MainWindow;
				double iH, iW;
				double iX, iY;
				double cX0, cX1, cX2;
				double cY0, cY1, cY2;

				if (!System.IO.File.Exists(m_path))
				{
					m_rootControl.textContent.Text += "没有找到文件：\"" + m_path + "\"\r\n";

					return;
				}

				if (m_xe.Name == "imageShape")
				{
					foreach (XmlAttribute att in m_xe.Attributes)
					{
						switch (att.Name)
						{
							case "ImageName":
							case "Height":
							case "Width":
							case "NineGrid":
							case "NGX":
							case "NGY":
							case "NGWidth":
							case "NGHeight":
							case "mirrorType":
							case "X":
							case "Y":
							case "Anchor":
							case "angle":
								break;
							default:
								{
									m_rootControl.textContent.Text += ("attr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
								}
								break;
						}
					}
				}

				#region Width & Height
				System.Drawing.Bitmap bmp = new System.Drawing.Bitmap(m_path);
				float m_perDpiX = bmp.HorizontalResolution / pW.m_dpiSysX;
				float m_perDpiY = bmp.VerticalResolution / pW.m_dpiSysY;
				m_imgWidth = bmp.Size.Width;
				m_imgHeight = bmp.Size.Height;
				double perX = 1.0d, perY = 1.0d, perDx = 0.0d, perDy = 0.0d;
				double curCanvasWidth = ((Canvas)this.Parent).Width;
				double curCanvasHeight = ((Canvas)this.Parent).Height;
				bool isNg = false;

				if (m_xe.GetAttribute("Height") != null && m_xe.GetAttribute("Height") != "")
				{
					iH = double.Parse(m_xe.GetAttribute("Height"));
					mx_ctrR0.Height = new GridLength(iH);
				}
				else
				{
					iH = m_imgHeight;
					mx_ctrR0.Height = new GridLength(curCanvasHeight);
				}
				if (m_xe.GetAttribute("Width") != null && m_xe.GetAttribute("Width") != "")
				{
					iW = double.Parse(m_xe.GetAttribute("Width"));
					mx_ctrC0.Width = new GridLength(iW);
				}
				else
				{
					iW = m_imgWidth;
					mx_ctrC0.Width = new GridLength(curCanvasWidth);
				}
				#endregion

				#region NineGrid
				if (m_xe.GetAttribute("NineGrid") == "true")
				{
					isNg = true;
					if (m_xe.GetAttribute("NGX") != "")
					{
						double ngX = double.Parse(m_xe.GetAttribute("NGX"));

						this.mx_ctrC0.MinWidth = iW;
						this.mx_ngc0.Width = new GridLength(ngX);
						this.mx_ngc2.Width = new GridLength((double)m_imgWidth - ngX);
						perX = ngX / (double)m_imgWidth;
						//this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Visible;

						iW = ngX;
					}
					else
					{
						this.mx_ngc0.Width = new GridLength((double)m_imgWidth);
						//this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Collapsed;
					}
					if (m_xe.GetAttribute("NGY") != "")
					{
						double ngY = double.Parse(m_xe.GetAttribute("NGY"));

						this.mx_ctrR0.MinHeight = iH;
						this.mx_ngr0.Height = new GridLength(ngY);
						this.mx_ngr2.Height = new GridLength((double)m_imgHeight - ngY);
						perY = ngY / (double)m_imgHeight;
						//this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Visible;

						iH = ngY;
					}
					else
					{
						this.mx_ngr0.Height = new GridLength((double)m_imgHeight);
						//this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Collapsed;
					}
					if (m_xe.GetAttribute("NGWidth") != "")
					{
						perDx = double.Parse(m_xe.GetAttribute("NGWidth")) / (double)m_imgWidth;
					}
					else
					{
					}
					if (m_xe.GetAttribute("NGHeight") != "")
					{
						perDy = double.Parse(m_xe.GetAttribute("NGHeight")) / (double)m_imgHeight;
					}
					else
					{
					}
				}
				else
				{
					isNg = false;
					this.mx_ngc0.Width = new GridLength(iW);
					this.mx_ngr0.Height = new GridLength(iH);
					//this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Collapsed;
					//this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Collapsed;
				}
				cX0 = iW;
				cX2 = m_imgWidth - iW;
				cY0 = iH;
				cY2 = m_imgHeight - iH;

				m_dW = iW;
				m_dH = iH;

				Rect[][] viewRect = new Rect[3][];
				viewRect[0] = new Rect[3];
				viewRect[1] = new Rect[3];
				viewRect[2] = new Rect[3];

				viewRect[0][0] = new Rect(0, 0, perX, perY);
				viewRect[0][1] = new Rect(perX, 0, perDx, perY);
				viewRect[0][2] = new Rect(perX, 0, 1 - perX, perY);
				viewRect[1][0] = new Rect(0, perY, perX, perDy);
				viewRect[1][1] = new Rect(perX, perY, perDx, perDy);
				viewRect[1][2] = new Rect(perX, perY, 1 - perX, perDy);
				viewRect[2][0] = new Rect(0, perY, perX, 1 - perY);
				viewRect[2][1] = new Rect(perX, perY, perDx, 1 - perY);
				viewRect[2][2] = new Rect(perX, perY, 1 - perX, 1 - perY);

				this.mx_ngBrush00.Viewbox = viewRect[0][0];
				this.mx_ngBrush01.Viewbox = viewRect[0][1];
				this.mx_ngBrush02.Viewbox = viewRect[0][2];
				this.mx_ngBrush10.Viewbox = viewRect[1][0];
				this.mx_ngBrush11.Viewbox = viewRect[1][1];
				this.mx_ngBrush12.Viewbox = viewRect[1][2];
				this.mx_ngBrush20.Viewbox = viewRect[2][0];
				this.mx_ngBrush21.Viewbox = viewRect[2][1];
				this.mx_ngBrush22.Viewbox = viewRect[2][2];
				#endregion NineGrid

				#region mirrorType(翻转)
				if (m_xe.GetAttribute("mirrorType") != "")
				{
					int mirrorType = int.Parse(m_xe.GetAttribute("mirrorType"));

					switch(mirrorType)
					{
						case 1:
							{
								//this.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#88cc88ff"));
								mx_ngBrush00.Transform = new ScaleTransform(-1.0f, 1.0f, cX0 / 2, cY0 / 2);
								mx_ngBrush01.Transform = new ScaleTransform(-1.0f, 1.0f, mx_ngc1.ActualWidth / 2, cY0 / 2);
								mx_ngBrush02.Transform = new ScaleTransform(-1.0f, 1.0f, cX2 / 2, cY0 / 2);
								mx_ngBrush10.Transform = new ScaleTransform(-1.0f, 1.0f, cX0 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush11.Transform = new ScaleTransform(-1.0f, 1.0f, mx_ngc1.ActualWidth / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush12.Transform = new ScaleTransform(-1.0f, 1.0f, cX2 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush20.Transform = new ScaleTransform(-1.0f, 1.0f, cX0 / 2, cY2 / 2);
								mx_ngBrush21.Transform = new ScaleTransform(-1.0f, 1.0f, mx_ngc1.ActualWidth / 2, cY2 / 2);
								mx_ngBrush22.Transform = new ScaleTransform(-1.0f, 1.0f, cX2 / 2, cY2 / 2);
							}
							break;
						case 2:
							{
								//this.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#88ffcc88"));
								mx_ngBrush00.Transform = new ScaleTransform(1.0f, -1.0f, cX0 / 2, cY0 / 2);
								mx_ngBrush01.Transform = new ScaleTransform(1.0f, -1.0f, mx_ngc1.ActualWidth / 2, cY0 / 2);
								mx_ngBrush02.Transform = new ScaleTransform(1.0f, -1.0f, cX2 / 2, cY0 / 2);
								mx_ngBrush10.Transform = new ScaleTransform(1.0f, -1.0f, cX0 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush11.Transform = new ScaleTransform(1.0f, -1.0f, mx_ngc1.ActualWidth / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush12.Transform = new ScaleTransform(1.0f, -1.0f, cX2 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush20.Transform = new ScaleTransform(1.0f, -1.0f, cX0 / 2, cY2 / 2);
								mx_ngBrush21.Transform = new ScaleTransform(1.0f, -1.0f, mx_ngc1.ActualWidth / 2, cY2 / 2);
								mx_ngBrush22.Transform = new ScaleTransform(1.0f, -1.0f, cX2 / 2, cY2 / 2);
							}
							break;
						case 3:
							{
								//this.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#8888ffcc"));
								mx_ngBrush00.Transform = new ScaleTransform(-1.0f, -1.0f, cX0 / 2, cY0 / 2);
								mx_ngBrush01.Transform = new ScaleTransform(-1.0f, -1.0f, mx_ngc1.ActualWidth / 2, cY0 / 2);
								mx_ngBrush02.Transform = new ScaleTransform(-1.0f, -1.0f, cX2 / 2, cY0 / 2);
								mx_ngBrush10.Transform = new ScaleTransform(-1.0f, -1.0f, cX0 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush11.Transform = new ScaleTransform(-1.0f, -1.0f, mx_ngc1.ActualWidth / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush12.Transform = new ScaleTransform(-1.0f, -1.0f, cX2 / 2, mx_ngr1.ActualHeight / 2);
								mx_ngBrush20.Transform = new ScaleTransform(-1.0f, -1.0f, cX0 / 2, cY2 / 2);
								mx_ngBrush21.Transform = new ScaleTransform(-1.0f, -1.0f, mx_ngc1.ActualWidth / 2, cY2 / 2);
								mx_ngBrush22.Transform = new ScaleTransform(-1.0f, -1.0f, cX2 / 2, cY2 / 2);
							}
							break;
						default:
							break;
					}
				}
				#endregion

				#region X , Y & Anchor
				if (m_xe.GetAttribute("X") != "")
				{
					iX = double.Parse(m_xe.GetAttribute("X"));
				}
				else
				{
					iX = 0;
				}
				if (m_xe.GetAttribute("Y") != "")
				{
					iY = double.Parse(m_xe.GetAttribute("Y"));
				}
				else
				{
					iY = 0;
				}

				bool isSpecial = true;
				
				if(isNg == false)
				{
				}
				else
				{
					iW = curCanvasWidth;
					iH = curCanvasHeight;
				}
				if (m_xe.GetAttribute("Anchor") != "")
				{
					int anchor = int.Parse(m_xe.GetAttribute("Anchor"));

					if ((anchor & 0x01) > 0)
					{
						//水平居中
						//iX = iX + (((Canvas)this.Parent).Width - curCanvasWidth) / 2;
						iX = iX + (((Canvas)this.Parent).Width - iW) / 2;
					}
					if ((anchor & 0x02) > 0)
					{
						//垂直居中
						//iY = iY + (((Canvas)this.Parent).Height - curCanvasHeight) / 2;
						iY = iY + (((Canvas)this.Parent).Height - iH) / 2;
					}
					if ((anchor & 0x04) > 0)
					{
						//左对齐
					}
					if ((anchor & 0x08) > 0)
					{
						//右对齐
						//iX = iX + (((Canvas)this.Parent).Width - curCanvasWidth);
						iX = iX + (((Canvas)this.Parent).Width - iW);
					}
					if ((anchor & 0x10) > 0)
					{
						//上对齐
					}
					if ((anchor & 0x20) > 0)
					{
						//底部对齐
						//iY = iY + (((Canvas)this.Parent).Height - curCanvasHeight);
						iY = iY + (((Canvas)this.Parent).Height - iH);
					}
				}
				Canvas.SetLeft(mx_rootFrame, iX);
				Canvas.SetTop(mx_rootFrame, iY);
				#endregion

				if(m_xe.GetAttribute("angle") != "")
				{
					double dAngle = double.Parse(m_xe.GetAttribute("angle"));

					this.mx_angle.Angle = dAngle;
				}

				#region ani(动画)
				int iFrame = 0;
				double sTime = 0.0d;

				foreach (AniNode aniNode in m_aniNodes)
				{
					drawFrame(aniNode, ref iFrame, ref sTime);
				}
				mx_aniFrame.Duration = TimeSpan.FromSeconds(sTime);
				mx_aniX.Duration = TimeSpan.FromSeconds(sTime);
				mx_aniY.Duration = TimeSpan.FromSeconds(sTime);
				mx_aniW.Duration = TimeSpan.FromSeconds(sTime);
				mx_aniH.Duration = TimeSpan.FromSeconds(sTime);
				if (m_enLoop == false)
				{
					mx_aniFrame.RepeatBehavior = new RepeatBehavior(1);
					mx_aniX.RepeatBehavior = new RepeatBehavior(1);
					mx_aniY.RepeatBehavior = new RepeatBehavior(1);
					mx_aniW.RepeatBehavior = new RepeatBehavior(1);
					mx_aniH.RepeatBehavior = new RepeatBehavior(1);
				}
				#endregion

				m_loaded = true;
			}
		}

		private void imageFrame_Unloaded(object sender, RoutedEventArgs e)
		{
// 			if (m_imgSource != null)
// 			{
// 				m_imgSource.StreamSource.Dispose();
// 			}
		}
	}
}
