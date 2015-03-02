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
using System.Windows.Forms;
using System.IO;

namespace UIEditor
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void openProj(object sender, RoutedEventArgs e)
        {
//             OpenFileDialog openFileDialog = new OpenFileDialog();
//             openFileDialog.Title = "选择文件";
//             openFileDialog.Filter = "ryrp文件|*.ryrp|所有文件|*.*";
//             openFileDialog.FileName = string.Empty;
//             openFileDialog.FilterIndex = 1;
//             openFileDialog.RestoreDirectory = true;
//             openFileDialog.DefaultExt = "ryrp";
//             DialogResult result = openFileDialog.ShowDialog();
//             if (result == System.Windows.Forms.DialogResult.Cancel)
//             {
//                 return;
//             }
//             string fileName = openFileDialog.FileName;
//             this.pro.Content = fileName;
//             //this.textBox1.Text = fileName;
            FolderBrowserDialog openFolderDialog = new FolderBrowserDialog();
            openFolderDialog.Description = "选择UI所在文件夹";
            openFolderDialog.SelectedPath = "E:\\mmo2013001\\artist\\version_backup\\ResourceDsKr_dev\\ui\\free";
            DialogResult result = openFolderDialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.Cancel)
            {
                return;
            }
            string path = openFolderDialog.SelectedPath;
//            string files = "";
            int i = 0;

            this.treePro.Header = path;
            TreeViewItem treeUI = new TreeViewItem();
            treeUI.Header = "UI";
            treeUI.Name = "treeUI";
            this.treePro.Items.Add(treeUI);
            DirectoryInfo di = new DirectoryInfo(path);
//             foreach (var dri in di.GetDirectories())
//                 files = files + dri.Name + " ";
            foreach (var dri in di.GetFiles("*.xml"))
            {
                i++;

                TreeViewItem treeUIChild = new TreeViewItem();
                treeUIChild.Header = dri.Name;
                treeUI.Items.Add(treeUIChild);
            }
            this.treePro.Header = path;
            this.treePro.IsExpanded = true;
            treeUI.IsExpanded = true;
        }

    }
}
