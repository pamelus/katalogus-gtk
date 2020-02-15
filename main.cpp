#include <gtkmm.h>
#include <libglademm.h>
#include <libglademm/xml.h>
#include "models.hpp"

class MainWindow : public Gtk::Window {
	private:
		Gtk::TreeView * wList;
		Gtk::Statusbar * wStatus;
		Glib::RefPtr<Gtk::ListStore> list;
		
		ListModel lm;
	public:
		MainWindow(BaseObjectType* base_object, const Glib::RefPtr<Gnome::Glade::Xml>& glade_xml);
		~MainWindow();
		
		void OnNew();
		void OnOpen();
		void OnSave();
		
		void OnAdd();
		void OnEdit();
		void OnDelete();
		
		void OnSearch();
		void OnStat();
		void OnReport();
		void OnAsc();
		void OnDesc();
		
		void OnForward();
		void OnBackward();	
};

MainWindow::MainWindow(BaseObjectType* base_object, const Glib::RefPtr<Gnome::Glade::Xml>& xml):
Gtk::Window(base_object) {
	xml->get_widget("list", wList);
	xml->get_widget("status", wStatus);
	
	list = Gtk::ListStore::create(lm);
	wList->set_model(list);
	wList->append_column_editable("Nazwa", lm.name);
	wList->append_column_editable("Nośnik", lm.medium);
	wList->append_column("Styl", lm.genre);
	
	// menu
	
	// buttony na toolbarze
	Gtk::ToolButton * btns[12];
	for(int i = 0; i < 12; i++) {
		char pszBuffer[32];
		sprintf(pszBuffer, "toolbutton%d", i+1);
		xml->get_widget(pszBuffer, btns[i]);
	}
	
	btns[0]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnNew));
	btns[1]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnOpen));
	btns[2]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnSave));
	btns[3]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnAdd));
	btns[4]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnEdit));
	btns[5]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnDelete));
	btns[6]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnSearch));
	btns[7]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnStat));
	btns[8]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnReport));
	(dynamic_cast<Gtk::ToggleToolButton *>(btns[9]))->signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::OnAsc));
	(dynamic_cast<Gtk::ToggleToolButton *>(btns[10]))->signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::OnDesc));
	btns[11]->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnBackward));
}

MainWindow::~MainWindow() { }

void MainWindow::OnNew() {
	printf("Button new pressed\n");
}

void MainWindow::OnOpen() {
	printf("Button open pressed\n");
}

void MainWindow::OnSave() {
	printf("Button save pressed\n");
}
		
void MainWindow::OnAdd() {
	Gtk::TreeModel::iterator id = list->append();
	Gtk::TreeModel::Row row = *id;
	
	row[lm.name] = "Nienazwany";
	row[lm.medium] = "";
	row[lm.genre] = "heavy";
}

void MainWindow::OnEdit() {
	printf("Button edit pressed\n");
}

void MainWindow::OnDelete() {
	printf("Button delete pressed\n");
}
		
void MainWindow::OnSearch() {
	printf("Button search pressed\n");
}

void MainWindow::OnStat() {
	printf("Button stat pressed\n");
}

void MainWindow::OnReport() {
	printf("Button report pressed\n");
}

void MainWindow::OnAsc() {
	printf("Button asc pressed\n");
}

void MainWindow::OnDesc() {
	printf("Button desc pressed\n");
}

void MainWindow::OnForward() {
	printf("Button forward pressed\n");
}

void MainWindow::OnBackward() {
	printf("Button backward pressed\n");
}


int main (int argc, char *argv[]) {
	Gtk::Main kit(argc, argv); 
	Glib::RefPtr<Gnome::Glade::Xml> xml = Gnome::Glade::Xml::create("interfejs.glade");
	
	MainWindow * main;
	xml->get_widget_derived("main", main);
	Gtk::Main::run(*main);
	return 0; 
}
