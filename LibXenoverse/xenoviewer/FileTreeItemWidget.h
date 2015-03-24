#ifndef FILE_TREE_ITEM_WIDGET_H_INCLUDED
#define FILE_TREE_ITEM_WIDGET_H_INCLUDED

class ESKOgre;
class EMDOgre;
class EANOgre;

class FileTreeItemWidget : public QTreeWidgetItem {
public:
	FileTreeItemWidget(QTreeWidget *parent);

	enum FileTreeItemType {
		ItemSkeleton,
		ItemAnimationPack,
		ItemAnimation,
		ItemModelPack,
		ItemModel,
		ItemMesh,
		ItemSubmesh,
		ItemMaterialPack,
		ItemMaterial,
		ItemTexturePack,
		ItemTexture
	};

	FileTreeItemType getType() {
		return type;
	}

	FileTreeItemWidget *getMatchType(FileTreeItemType match_type) {
		if (match_type == type) {
			return this;
		}
		else {
			return NULL;
		}
	}

protected:
	FileTreeItemType type;
};

class SkeletonItemWidget : public FileTreeItemWidget {
protected:
	ESKOgre *data_ptr;
public:
	SkeletonItemWidget(ESKOgre *data, QTreeWidget *parent);
	~SkeletonItemWidget();

	ESKOgre *getData() {
		return data_ptr;
	}
};

class ModelPackItemWidget : public FileTreeItemWidget {
protected:
	EMDOgre *data_ptr;
public:
	ModelPackItemWidget(EMDOgre *data, QTreeWidget *parent);
	~ModelPackItemWidget();

	EMDOgre *getData() {
		return data_ptr;
	}

	void updateText();
};


class AnimationPackItemWidget : public FileTreeItemWidget {
protected:
	EANOgre *data_ptr;
public:
	AnimationPackItemWidget(EANOgre *data, QTreeWidget *parent);

	EANOgre *getData() {
		return data_ptr;
	}
};



class AnimationItemWidget : public FileTreeItemWidget {
protected:
	EANAnimation *data_ptr;
public:
	AnimationItemWidget(EANAnimation *data, QTreeWidget *parent);

	EANAnimation *getData() {
		return data_ptr;
	}
};



#endif