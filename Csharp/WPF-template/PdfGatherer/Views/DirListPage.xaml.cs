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

namespace PdfGatherer.Views
{
    /// <summary>
    /// Interaction logic for DirList.xaml
    /// </summary>
    public partial class DirListPage : UserControl
    {

        public DirListPage()
        {
            InitializeComponent();

            foreach (String s in Core.listEntries)
            {
                ViewModels.DirListVM.listItemEntries.Add(s);
            }
        }

        private void OnLBSelectionChange(object sender, RoutedEventArgs e)
        {
            // stub
        }

        private void DirListCtxMenuClick(object sender, RoutedEventArgs e)
        {
            MenuItem itm = (MenuItem)e.Source;
            MessageBox.Show(itm.Name);
        }
    }
}
