using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace PdfGatherer
{
    public class Core
    {
        public static bool dirAv = false;
        public static bool fileAv = false;

        public static List<String> listEntries = new List<String>();

        public static void TestInit()
        {
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
            listEntries.Add("Entry template");
        }
    }

    public class ListEntry : INotifyPropertyChanged
    {
        private string _text;

        // a property.
        public string Text
        {
            get { return _text; }
            set
            {
                if (_text != value)
                {
                    _text = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Text)));
                }
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
    }

    public class EntryCollection : ObservableCollection<ListEntry>
    {
        public void Add(string text)
        {
            this.Add(new ListEntry { Text = text });
        }
    }
}
