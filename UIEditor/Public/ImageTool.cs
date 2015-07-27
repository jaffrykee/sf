using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace UIEditor.Public
{
	public class ImageTool {

		private int width = 1024;
		private int height = 1024;
		private List<Size> picSize = new List<Size>();
		private List<string> resName = new List<string>();
		public static List<Rectangle> setDone = new List<Rectangle>();
		public static int IMAGE_UI = 0;
		public static int IMAGE_FONT = 1;

		
		private List<Rectangle> orderImage(List<Rectangle> images, int tgt)
		{
			int swaptimes = 0;
			do
			{ 
				//冒泡排序
				swaptimes = 0;
				for (int i = 0, size = images.size(); i < size - 1; i++) {
					long a = 0;
					long b = 0;
					if(tgt == 0){//面积
						a = images.get(i).area;
						b = images.get(i + 1).area;
					} else if(tgt == 1){//宽度
						a = images.get(i).w;
						b = images.get(i + 1).w;
					} else if(tgt == 2){//高度
						a = images.get(i).h;
						b = images.get(i + 1).h;
					} else if(tgt == 3){//优化面积
						int rateA = areaRate(images.get(i));
						int rateB = areaRate(images.get(i + 1));
						a = images.get(i).area * rateA;
						b = images.get(i + 1).area * rateB;
					}
					if (a < b) { //
						ImageBox ibb = new ImageBox(null, null, null);
						ibb = images.get(i);
						images.remove(i);
						images.add(i, images.get(i));
						images.remove(i + 1);
						images.add(i + 1, ibb);
						swaptimes++;
					}
				}
			} while (swaptimes > 0);
			return images;
		}

		public void arrangeUIImage(String imagePath, int imageType) {
			List<List<Rectangle>> lstLstImg;
			resName = new List<string>();
			int ssw = 2;
			int ssh = 2;
			picSize = new List<Size>();
			for (int i = 0; i < 10; i++)
			{
				//图片放置范围可选像素表
				Size size = new Size();

				size.Width = (int) Math.Pow((double) 2, (double) i) * ssw;
				size.Height = (int) Math.Pow((double) 2, (double) i) * ssh;
				picSize.Add(size);
			}
			foreach (List<Rectangle> lstImg in lstLstImg)
			{
				if(lstImg == null){
					//空文件夹
					continue;
				}
				bool sizeOutOfRange = false;
				long curArea = 0;
				int sizeIndex = 0;
				int minSizeIndex = 0;
				int mh = 0;//拼图高度
				int mw = 0;//拼图宽度
				lstImg = orderImage(lstImg, 1);//宽度由大到小排序
				for(ImageBox ib:ims){
					if(ib.w > picSize.get(picSize.size() - 1)[0] || ib.h > picSize.get(picSize.size() - 1)[1]){
						System.out.println("xxxxxxxxxxxxxxx  拼图失败  xxxxxxxxxxxxxxx");
						System.out.println(ims.get(0).fileName + " :");
						System.out.println(ib.name + "图片尺寸超出拼图最大尺寸!");
					}else{
						break;
					}
				}
				int minW = ims.get(0).w;
				ims = orderImage(ims, 3);//面积排序
				for (; sizeIndex < picSize.size();) {//查找最优面积
					for (int sid = sizeIndex; sid < picSize.size(); sid++) {
						if ((picSize.get(sid))[0] >= minW) {
							minW = (picSize.get(sid))[0];
							sizeIndex = sid;
							break;
						}
					}
					width = (picSize.get(sizeIndex))[0];
					height = (picSize.get(sizeIndex))[1];
					setDone = new ArrayList<ImageBox>();
					for (ImageBox ib : ims) {
						if(setImagePosition(ib)){
	//                        System.out.println(ib);
							setDone.add(ib);
						}
					}
					mh = 0;
					mw = 0;
					int cw = 0;
					int ch = 0;
					for (ImageBox ib : ims) { //获取当前所拼大图高度和宽度
						cw = ib.x + ib.w;
						if(cw > mw){
							mw = cw;
						}
						ch = ib.y + ib.h;
						if (ch > mh) {
							mh = ch;
						}
					}
					curArea = mw * mh;
					if (mw <= width && mh <= height) {//不能超高
						minSizeIndex = sizeIndex;
						sizeOutOfRange = false;
						break;
					}else if((mh > height || mw > width) && sizeIndex == picSize.size() - 1){
						sizeOutOfRange = true;  //拼图大小越界
						System.out.println("xxxxxxxxxxxxxxx  拼图失败  xxxxxxxxxxxxxxx");
						System.out.println(ims.get(0).fileName + "超出拼图最大尺寸!");
					}
					sizeIndex++;
				}
				//----------------------------------
				if(!sizeOutOfRange){
					setDone = new ArrayList<ImageBox>();
					width = picSize.get(minSizeIndex)[0];
					height = picSize.get(minSizeIndex)[1];
					System.out.println("---------------  拼图成功  ---------------");
					System.out.println("name = " + ims.get(0).fileName + ", width = " + width + ", height = " + height);
					BufferedImage bi = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
					Graphics g = bi.getGraphics();
					for (ImageBox ib : ims) {
						if(setImagePosition(ib)){
							setDone.add(ib);
							g.drawImage(ib.image, ib.x + 1, ib.y + 1, null); //加大一像素
							setBorderRGB(bi, ib);// 设置边框
	//                        System.out.println(ib);
						}
					}
					try {
						String FileName = imagePath + ims.get(0).fileName + ".tga";
						if (imageType == IMAGE_UI) {
							outputTgaImage(bi, width, height, FileName, false);
							saveUIImageXml(imagePath + ims.get(0).fileName + ".xml", ims);
						} else if (imageType == IMAGE_FONT) {
							outputTgaImage(bi, width, height, FileName, true);
							saveFontImageXml(imagePath + ims.get(0).fileName + ".xml", ims);
						}
					} catch (Exception ex) {
						Logger.getLogger(ImageTool.class.getName()).log(Level.SEVERE, null, ex);
					}
					resName.add(ims.get(0).fileName);
				}
			}
			if (imageType == IMAGE_UI) {
				try {
					saveUIResourceXml(imagePath + "resource.xml", resName);
				} catch (FileNotFoundException ex) {
					Logger.getLogger(ImageTool.class.getName()).log(Level.SEVERE, null, ex);
				} catch (XmlPullParserException ex) {
					Logger.getLogger(ImageTool.class.getName()).log(Level.SEVERE, null, ex);
				} catch (IOException ex) {
					Logger.getLogger(ImageTool.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}

		private void setBorderRGB(BufferedImage bi, ImageBox ib){
			for(int i = ib.x; i < ib.x + ib.w; i++){ //上下边界 + 四个顶点
				int rgbtop = bi.getRGB(i, ib.y + 1);//上边界 + 上顶点
				bi.setRGB(i, ib.y, rgbtop);
				int rgbbtm = bi.getRGB(i, ib.y + ib.h - 2);//下边界 + 下顶点
				bi.setRGB(i, ib.y + ib.h - 1, rgbbtm);
			}
			//-----
			for(int i = ib.y + 1; i < ib.y + ib.h - 1; i++){ //左右边界
				int rgblft = bi.getRGB(ib.x + 1, i);//左边界
				bi.setRGB(ib.x, i, rgblft);
				int rgbrht = bi.getRGB(ib.x + ib.w - 2, i);//右边界
				bi.setRGB(ib.x + ib.w - 1, i, rgbrht);
			}
		}
    
		private boolean  setImagePosition(ImageBox ib){
			if(ib.w > width || ib.h > height){
				return false;
			}
			int curY = 0;
			for( ; curY <= height - ib.h; ){
				boolean set = false;
				int addy = 1024;
				for(int curX = 0; curX <= width - ib.w; ){
					addy = 1024;
					ib.x = curX;
					ib.y = curY;
					if(setDone.isEmpty()){
						set = true;
						break;
					}
					for(int i = 0; i < setDone.size(); i++){//判断与已放置图片是否相交
						ImageBox bb = setDone.get(i);
						if(ib.collidesWith(bb)){//如果相交，右移
							ib.x += bb.w + bb.x - ib.x;//右移相交图片宽度
							curX = ib.x;
							i = 0;//重新遍历比较是否相交
							if(bb.y + bb.h - ib.y < addy){
								addy = bb.y + bb.h - ib.y;//下移最小差值
							}
							if(ib.x > width - ib.w){
								break;
							}
						} else if(i == setDone.size() - 1){//全部不相交，则放置
							set = true;
						}
					}
					if(set){//放置，结束循环
						break;
					}
				}
				if(ib.x > width - ib.w){//宽度越界，下移
					curY += addy;
					continue;
				}
				if(!set){//如果当前高度全部相交，下移
					curY += addy;
				} else { //否则放置，结束循环
					break;
				}
			}
			if(curY <= height - ib.h){
				return true;
			}else{
	//            System.out.println(ib.name + "'s" + " size OutofRange!");
	//            System.out.println("Y" + "=" + curY);
			}
			return false;
		}

		private int areaRate(ImageBox ib){
			int ar = 1;
			if(ib.w > 0 && ib.h > 0){
				ar = (ib.w >= ib.h) ? (ib.w / ib.h) : (ib.h / ib.w);
				ar = (int)Math.sqrt((double)ar);
			}
			return ar;
		}

		private void saveUIImageXml(String path, ArrayList<ImageBox> ims) throws Exception {
			Document doc = XmlUtils.blankDocument("UIImageResource");
			Element root = doc.getDocumentElement();
			for (ImageBox ib : ims) {
				Element res = XmlUtils.createChild(doc, root, "Image");
				res.setAttribute("Name", ib.name.substring(0, ib.name.length() - 4));
				res.setAttribute("X", ib.x + 1 + ""); //加大一像素
				res.setAttribute("Y", ib.y + 1 + "");
				res.setAttribute("Width", ib.w - 2 + "");
				res.setAttribute("Height", ib.h - 2 + "");
			}
			XmlUtils.save(path, doc);
		}

		private void saveFontImageXml(String path, ArrayList<ImageBox> ims) throws Exception {
			Document doc = XmlUtils.blankDocument("font");
			Element root = doc.getDocumentElement();
			for (ImageBox ib : ims) {
				Element res = XmlUtils.createChild(doc, root, "c");
				res.setAttribute("v", ib.name.substring(0, ib.name.length() - 4));
				res.setAttribute("x", ib.x + 1 + ""); //加大一像素
				res.setAttribute("y", ib.y + 1 + "");
				res.setAttribute("w", ib.w - 2 + "");
				res.setAttribute("h", ib.h - 2 + "");
			}
			XmlUtils.save(path, doc);
		}

		private void saveUIResourceXml(String path, ArrayList<String> resName) throws FileNotFoundException, XmlPullParserException, IOException{
			FileInputStream is = new FileInputStream(path);
			KXmlParser parser = new KXmlParser();
			parser.setInput(is, null);
			parser.next();
			parser.require(XmlPullParser.START_TAG, null, "BoloUI");
			Vector<String> oldResName = parserUIResourceXml(parser);//读取旧资源
			parser.require(XmlPullParser.END_TAG, null, "BoloUI");
			parser.next();
			parser.require(XmlPullParser.END_DOCUMENT, null, null);
			is.close();
			is = null;
			try {
				Document doc = XmlUtils.blankDocument("BoloUI");
				Element root = doc.getDocumentElement();
				for (String name : oldResName) {//保留旧资源
					Element res = XmlUtils.createChild(doc, root, "resource");
					res.setAttribute("name", name);
				}
				for (String name : resName) {
					int equals = 0;
					for(String oldRN : oldResName){
						if(oldRN.equals(name)){
							equals++;
							break;
						}
					}
					if(equals == 0){//避免重复
						Element res = XmlUtils.createChild(doc, root, "resource");
						res.setAttribute("name", name);
					}
				}
				XmlUtils.save(path, doc);
			} catch (Exception ex) {
				Logger.getLogger(ImageTool.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
    
		private Vector<String> parserUIResourceXml(KXmlParser parser) throws XmlPullParserException, IOException{
			Vector<String> res = new Vector<String>();
			do {
				parser.next();
				if (parser.getEventType() == XmlPullParser.START_TAG) { 
					res.add(parser.getAttributeValue(null, "name"));
				}
			} while (!(parser.getEventType() == XmlPullParser.END_TAG && parser.getName().equals("BoloUI")));
			return res;
		}

		public static void outputTgaImage(BufferedImage bi, int ibW, int ibH, String FileName, boolean mirror) throws IOException {
			byte[] buf = new byte[ibW * ibH * 4];
			int[] data = bi.getRGB(0, 0, ibW, ibH, null, 0, ibW);
			int ii = 0;
			if (mirror) {
				for (int i = 0; i < ibH - 1; i++) {
					for (int j = 0; j < ibW; j++) {
						int index = i * ibW + j;
						int argb = data[index];
						buf[ii * 4] = (byte) (argb & 0xff);
						buf[ii * 4 + 1] = (byte) ((argb & 0xff00) >> 8);
						buf[ii * 4 + 2] = (byte) ((argb & 0xff0000) >> 16);
						buf[ii * 4 + 3] = (byte) ((argb & 0xff000000) >> 24);
						ii++;
					}
				}
			} else {
				for (int i = ibH - 1; i >= 0; i--) {
					for (int j = 0; j < ibW; j++) {
						int index = i * ibW + j;
						int argb = data[index];
						buf[ii * 4] = (byte) (argb & 0xff);
						buf[ii * 4 + 1] = (byte) ((argb & 0xff00) >> 8);
						buf[ii * 4 + 2] = (byte) ((argb & 0xff0000) >> 16);
						buf[ii * 4 + 3] = (byte) ((argb & 0xff000000) >> 24);
						ii++;
					}
				}
			}
			ByteArrayOutputStream bos = new ByteArrayOutputStream();
			byte[] type_header = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			byte[] head = new byte[6];
			head[0] = (byte) (ibW % 256);
			head[1] = (byte) (ibW / 256);
			head[2] = (byte) (ibH % 256);
			head[3] = (byte) (ibH / 256);
			head[4] = 32;
			head[5] = 8;
			bos.write(type_header);
			bos.write(head);
			bos.write(buf);
			MyTools.writeToFile(FileName, bos.toByteArray());
		}
	}
}
